from utils import *

class Connection:
    def __init__(self, id, addr, sock, tipoCliente):
        self.type = tipoCliente
        self.id = id
        self.con = None
        self.addr = addr
        self.sock = sock

    def getId(self):
        return self.id

    def getConexao(self):
        return self.con

    # Adiciona o id do exibidor
    def estabelecerConexao(self, x):
        if (not isinstance(x, int )):
            print('Era esperado um ID ')
            return
        self.con = x

    # Retorna informação (Endereço, porta) do socket.
    def getaddr(self):
        return self.sock.getsockname()

    # Retorna o socket associado a um cliente (exibidor ou emissor)
    def getSocket(self):
        return self.sock

    def getTipoCliente(self):
        return self.type

    def __del__(self):
        self.sock.close()
        print('Fechando Conexao')

class Server:
    def __init__(self, port):
        self.port = port
        
        self.server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.server_socket.bind(("0.0.0.0", self.port))
        self.server_socket.listen()
        self.listaConexoes = []

    def __del__(self):
        for conn in self.listaConexoes:
            sock = conn.sock
            if (not sock._closed):
                idClienteFechar = self.getId(sock)
                data = (tipoMensagem["FLW"], serverID, idClienteFechar, 0)
                self.enviarMensagem(sock, data)
                flag_Sair = True

                while flag_Sair:
                    read_sockets, write_sockets, error_sockets = select.select([sock],[],[])
                    header, idOrigem, idDestino, aux = self.receberHeader(sock)

                    if (header == tipoMensagem["OK"] and idOrigem == idClienteFechar and idDestino == serverID):
                        flag_Sair = False
                    
                sock.close()
        self.server_socket.close()

    # Retorna o socket do cliente passando o id como parametro
    def getSocket(self, id):
        for conn in self.listaConexoes:
            if (conn.getId() == id):
                return conn.getSocket()
        return None

    # Retorna o socket do cliente passando pelo ID
    def getId(self, sock):
        for conn in self.listaConexoes:
            if conn.getSocket() == sock:
                return conn.getId()
        return None

    # Retorna uma lista de instâncias de listaConexoes possuído pelo servidor
    def getConexoes(self):
        conexoes = []
        for conn in self.listaConexoes:
            conexoes += [conn.getSocket()]
        return conexoes

    # Remove o cliente da lista passando o id ou socket
    def removeSocket(self, param):
        #ID
        if (param is int):
            for conn in self.listaConexoes:
                if (param == conn.getId()):
                    print(conn.getId())
                    self.listaConexoes.remove(conn)
                    return True
        #Socket
        else:
            for conn in self.listaConexoes:
                if (param == conn.getSocket()):
                    self.listaConexoes.remove(conn)
                    return True
        return False

    # Pega o primeiro id disponivel passando um id inicial como parametro
    def getIdsDisponiveis(self, valorInicial=2**12):
        ids = [x.getId() for x in self.listaConexoes]
        if ids is None:
            return valorInicial
        else:
            idx = valorInicial
            while True:
                if (idx == serverID):
                    print('ID para conectar nao disponivel')
                    return None
                if (idx in ids):
                    idx += 1
                else:
                    break
            return idx

    def novaConexao(self):
        print('Nova Conexao')
        new_sock, addr = self.server_socket.accept()
        header = self.receberHeader(new_sock)

        tipoMensagemHeader = header[0]
        if (tipoMensagemHeader != tipoMensagem["OI"]):
            return None

        idOrigem = header[1]

        #Enviar de volta pro cliente
        aux = [0,0,0,0]

        if (idOrigem == 0):
            id = self.getIdsDisponiveis(2**12)
            print('Conectando com Exibidor {}'.format(id))
            conn = Connection(id, addr, new_sock, tipoCliente['EXIBIDOR'])
            self.listaConexoes.append(conn)
            aux[0] = tipoMensagem["OK"]
            aux[1] = serverID
            aux[2] = id

        elif (0 < idOrigem < 2**12):
            print('Conectando com Emissor {}'.format(aux[2]))
            conn = Connection(idOrigem, addr, new_sock, tipoCliente['EMISSOR'])
            self.listaConexoes.append(conn)
            aux[0] = tipoMensagem["OK"]
            aux[2] = idOrigem
            
        elif (2**12 <= idOrigem < 2**13 - 1):
            sock = self.getSocket(idOrigem)
            if(sock is not None):
                aux[0] = tipoMensagem["OK"]
                aux[1] = serverID
                aux[2] = self.getIdsDisponiveis(1)
                print('Conectando com Emissor {}'.format(aux[2]))
                
                conn = Connection(aux[2], addr, new_sock, tipoCliente['EMISSOR'])
                self.listaConexoes.append(conn)
                conn.estabelecerConexao(idOrigem)
                strMsg = 'Emissor de ID '+str(aux[2])+' conectado \n'
                for conn in self.listaConexoes:
                    try:
                        if (conn.getTipoCliente() == tipoCliente['EXIBIDOR']):
                            header = (tipoMensagem["MSG"], serverID, conn.getId(), 0)
                            self.enviarMensagem(conn.getSocket(), header, strMsg)
                    except:
                        raise
            else:
                aux[0] = tipoMensagem["ERRO"]
                aux[1] = serverID
                raise

        self.enviarMensagem(new_sock, aux)
        return new_sock
   
    def iniciar(self):
        print("Servidor iniciado na porta " + str(self.port))
        print('Digite \'/ajuda\' para ver comandos disponiveis.')

        while True:
            listaSockets = [sys.stdin, self.server_socket] + self.getConexoes()

            try:
                read_sockets, write_sockets, error_sockets = select.select(listaSockets,[],[])
            except Exception as e:
                print('Erro na função Select')
                print('Lista de Sockets disponiveis\n', listaSockets)
                sys.exit()

            for sock in read_sockets:
                if sock == self.server_socket:
                    new_sock = self.novaConexao()
                
                elif sock == sys.stdin:
                    self.recebeComando()
    
                else:
                    self.getData(sock)

    # Recebe e retorna o dado do socket
    def receberMensagem(self, sock, size):
        try:
            data = sock.recv(size)
        except:
            addr = sock.getsockname()
            print("Cliente (%s, %s) esta offline" % addr)
            sock.close()
            self.listaConexoes.remove(sock)
            return None
        return data

    # Constroi o cabecalho concatenado a mensagem em formato binario e envia pelo socket
    def enviarMensagem(self, sock, header, data=''):
        if (header is not tuple):
            header = tuple(header)
        data = bytes(data, 'ascii')
        if (len(data) > 0 or tipoMensagem["MSG"] == header[0]):
            header = (*header, len(data), data)
            struct_aux = struct.Struct('! H H H H H ' + str(len(data)) + 's')
        else:
            struct_aux = Header.struct
        dataBytes = ctypes.create_string_buffer(struct_aux.size)
        struct_aux.pack_into(dataBytes, 0, *header)
        
        try:
            sock.send(dataBytes)
        except:
            print('Err oao enviar dados')
            return False
        return True

    # Método que retorna uma quantidade de dados utilizando recv
    def receberMensagem(self, sock, size):
        try:
            data = sock.recv(size)

            if (not data):
                print('Desconectando - Sem Dados Recebidos')
                sys.exit()
        except:
            print('Erro ao receber dados')
            return None
        return data

    def receberHeader(self, sock):
        data = self.receberMensagem(sock, Header.struct.size)
        return Header.struct.unpack(data)

    def recebeComando(self):
        comando = sys.stdin.readline()

        if (comando[:-1] == '/ajuda'):
            print('/status-- IDs e Conexoes Ativas')
            print('/sair-- Encerrar')

        elif (comando[:-1] == '/status'):
            if self.listaConexoes == []:
                print('Nenhuma conexao encontrada')
            for conn in self.listaConexoes:
                print(str(conn.getId()) + ' - ' + str(conn.getConexao()))

        elif (comando[:-1] == '/sair'):
            sys.exit()

    # Recebe os dados do socket e repassa a responsabilidade pra outro metodo
    def getData(self, sock):
        header = self.receberHeader(sock)

        if (header is None or len(header) < 4):
            aux_id = self.getId(sock)
            print('id:' + str(aux_id))
            self.removeSock(sock)
            listaConexoes.remove(sock)
            return
        else:
            head, idOrigem, idDestino, seqNum = header[:4]

        if (head == tipoMensagem["OK"]):
            self.msgTipoOk(sock, idOrigem, idDestino, seqNum)
        elif (head == tipoMensagem["ERRO"]):
            self.msgTipoErro(sock)
        elif (head == tipoMensagem["FLW"]):
            self.msgTipoFlw(sock)
        elif (head == tipoMensagem["MSG"]):
            self.msgTipoMsg(sock, idOrigem, idDestino, seqNum)
        elif (head == tipoMensagem["CREQ"]):
            self.msgTipoCreq(idOrigem, idDestino)
        elif (head == tipoMensagem["CLIST"]):
            pass
        else:
            return

    def msgTipoOk(self, sock, idOrigem, idDestino, seqNum):
        if (idDestino != serverID):
            try:
                header = (tipoMensagem["OK"], idOrigem, idDestino, seqNum)
                for conn in self.listaConexoes:
                    if conn.getSocket() == sock:
                        continue
                    self.enviarMensagem(conn.getSocket(), header)
            except Exception as e:
                raise

    def msgTipoErro(self, sock):
        pass

    def msgTipoFlw(self, sock):
        header = (tipoMensagem["OK"], serverID, self.getId(sock), 0)
        self.enviarMensagem(sock, header)
        self.remove_sock(sock)

    def msgTipoMsg(self, sock, idOrigem, idDestino, seqNum):
        struct_H = struct.Struct('! H')
       
        length = struct_H.unpack(self.receberMensagem(sock, struct_H.size))[0]
        struct_aux = struct.Struct('! ' + str(length) + 's')
        data = self.receberMensagem(sock, struct_aux.size)


        if data:
            data = struct_aux.unpack(data)[0].decode('ascii')
            
            if idDestino == 0:
                for conn in self.listaConexoes:
                    if (conn.getId() == idOrigem):
                        continue

                    if (conn.getTipoCliente() == tipoCliente['EXIBIDOR']):
                            header = (tipoMensagem["MSG"], idOrigem, conn.getId(), seqNum)
                            self.enviarMensagem(conn.getSocket(), header, data)
                    
            else:
                idEscolhido = None
                for conn in self.listaConexoes:
                    if (idDestino == conn.getId()):
                        #print("Entrou no if de ver o ID")
                        idEscolhido = conn.getConexao()
                        #print("ID Escolhido", idEscolhido)
                        break
                if (idEscolhido is None):
                    print('ID escolhido nao encontrado')
                    return
                idEscolhidoAux = None
                for conn in self.listaConexoes:
                    if (idOrigem == conn.getId()):
                        idEscolhidoAux = conn.getConexao()
                        break
                if (idEscolhidoAux is None):
                    return

                try:
                    header = (tipoMensagem["MSG"], idOrigem, idEscolhido, seqNum)
                    self.enviarMensagem(self.getSocket(idEscolhido), header, data)

                    header = (tipoMensagem["MSG"], idOrigem, idEscolhidoAux, seqNum)
                    self.enviarMensagem(self.getSocket(idEscolhidoAux), header, data)
                except:
                    raise
        else:
            return

    def msgTipoCreq(self, idOrigem, idDestino):
        qtdConexoes = len(self.listaConexoes)
        if (qtdConexoes is None):
            return None

        struct_desc = '! H H H H H' + str(qtdConexoes) + 'H'
        struct_aux = struct.Struct(struct_desc)
        aux = ctypes.create_string_buffer(struct_aux.size)

        if (idDestino == 0):
            # Broadcast
            header = [tipoMensagem["CLIST"], serverID, 0, 0]
            data = header + [qtdConexoes]

            for conn in self.listaConexoes:
                data.append(conn.getId())

            for conn in self.listaConexoes:
                if (conn.getTipoCliente() == tipoCliente['EXIBIDOR']):
                    data[2] = conn.getId()
                    data_aux = tuple(data)
                    struct_aux.pack_into(aux, 0, *data_aux)
                    conn.getSocket().send(aux)
                    
        else: 
            idAux = 0
            for conn in self.listaConexoes:
                if (conn.getId() == idOrigem):
                    idAux = conn.getConexao()
                    break

            if (idAux == 0):
                return None

            header = [tipoMensagem["CLIST"], serverID, idAux, 0]
            data = header + [qtdConexoes]
            sock = None

            for conn in self.listaConexoes:
                data.append(conn.getId())
                if idAux == conn.getId():
                    sock = conn.getSocket()
            if (sock is None):
                return None
            data = tuple(data)
            struct_aux.pack_into(aux, 0, *data)
         
            try:
                sock.send(aux)
            except Exception as e:
                print('Erro ao enviar mensagem')
                raise


def main():
    if(len(sys.argv) >= 2):
        porta = int(sys.argv[1])
    else:
        porta = 50511
    servidor = Server(porta)
    servidor.iniciar()

if __name__ == "__main__":
    main()