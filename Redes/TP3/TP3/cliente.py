from utils import *

class Client:
    def __init__(self, host, porta):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.host = host
        self.porta = porta
        self.id = 0
        self.seqNum = 0

    def __del__(self):
        if (self.sock._closed == False):
            msg = (tipoMensagem["FLW"], self.id, serverID, 0)
            self.enviarMensagem(msg)
            while True:
                read_sockets, write_sockets, error_sockets = select.select([self.sock],[],[])
                header, idOrigem, idDestino, dummy = self.recebeHeader()
                if (header == tipoMensagem["OK"] and idOrigem == serverID and idDestino == self.id):
                    break
                
        self.sock.close()
        print('Erro no Cliente')

    # Faz uma requisição para conectar ao servidor
    def conectar(self, idRequisicao):
        self.sock.connect((self.host, self.porta))
        self.sock.settimeout(5)
        self.enviarMensagem((tipoMensagem["OI"], idRequisicao, serverID, 0))
        tipoMensagemHeader, idOrigem, idDestino, aux = self.recebeHeader()
       
        #Recebendo o OK, seta o identificador recebido
        if (tipoMensagemHeader == tipoMensagem["OK"] and idDestino != serverID and idDestino != 0):
            self.id = idDestino
            return True
        
        else:
            sys.exit(1)

    # Envia mensagem concatenada com o Header
    def enviarMensagem(self, header, msg=''):

        if (header is not tuple):
            header = tuple(header)
        msg = bytes(msg, 'ascii')

        if (len(msg) > 0 or tipoMensagem["MSG"] == header[0]):
            header = (*header, len(msg), msg)
            struct_aux = struct.Struct('! H H H H H ' + str(len(msg)) + 's')

        else:
            struct_aux = Header.struct

        msgEnviar = ctypes.create_string_buffer(struct_aux.size)
        struct_aux.pack_into(msgEnviar, 0, *header)
        
        try:
            self.sock.send(msgEnviar)
        except:
            print('Erro ao enviar mensagem')
            return False
        return True


    def receberMensagem(self, size):
        try:
            msg = self.sock.recv(size)
            if (not msg):
                print('\nDisconectado\n')
                self.sock.close()
                sys.exit()
        except:
            print('Erro ao receber mensagem')
            sys.exit()
        return msg

    #Extrai o cabeçalho do socket
    def recebeHeader(self):
        msg = self.receberMensagem(Header.struct.size)

        if (len(msg) != 8):
            return None

        return Header.struct.unpack(msg)

    def msgTipoFlw(self, idOrigem, idDestino):
        if (self.id != idDestino):
            return
        header = (tipoMensagem["OK"], self.id, serverID, 0)
        try:
            self.enviarMensagem(header)
        except Exception as e:
            raise
        self.sock.close()
        sys.exit(0)

    def getIdCliente(self):
        return self.id