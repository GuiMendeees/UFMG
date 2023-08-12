from cliente import *

class Emissor(Client):
    def __init__(self, host, porta, idExibidor = 2**12):
        super().__init__(host, porta)
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.idExibidor   = idExibidor 
     
    def iniciar(self):
        if (not self.conectar(self.idExibidor ) ):
            return False

        while True:
           
            listaSocket = [sys.stdin, self.sock]

            #Lista de Sockets
            read_sockets, write_sockets, error_sockets = select.select(listaSocket , [], [])

            for sock in read_sockets:
                if (sock == self.sock):
                    header = self.recebeHeader()

                    tipoMensagemHeader, idOrigem, idDestino, seqNum = header

                    if (tipoMensagemHeader == tipoMensagem["OK"]):
                        self.msgTipoOk(idOrigem, seqNum)
                    elif (tipoMensagemHeader == tipoMensagem["ERRO"]):
                        pass
                    elif (tipoMensagemHeader == tipoMensagem["FLW"]):
                        self.msgTipoFlw(idOrigem, idDestino)
                    elif (tipoMensagemHeader == tipoMensagem["MSG"]):
                        if (idDestino == self.id):
                            self.msgTipoMsg(idOrigem, seqNum)
                    elif (tipoMensagemHeader == tipoMensagem["CLIST"]):
                        pass
                    else:
                        continue

                elif (sock == sys.stdin):
                    print('Digite uma mensagem para todos ou\n')
                    print('/msgTO [id Exibidor] [Mensagem] -- Para mensagem direta')
                    msg = sys.stdin.readline()

                    if (msg[:-1] == '/sair'):
                        sys.exit()
                    else:
                        if (msg.find("/msgTO") == 0 and len(msg.split(" ")) > 2):
                            
                            idExibidor = int(msg.split(" ")[1])
                            print("Mensagem direta para o id {}".format(idExibidor))
                            msg_complete = str()
                            
                            for x in msg.split(" ")[2:]:
                                msg_complete += x + ' '
                            self.enviarMensagem((tipoMensagem["MSG"], self.id, idExibidor, self.seqNum), 
                            msg_complete)
                        else:
                            # broadcast
                            self.enviarMensagem((tipoMensagem["MSG"], self.id, 0, self.seqNum), msg)

    def receberMensagem(self, size):
        return super(Emissor, self).receberMensagem(size)

    def recebeHeader(self):
        return super(Emissor, self).recebeHeader()

    def msgTipoOk(self, idOrigem, seqNum):
        if (seqNum == self.seqNum):
            self.seqNum += 1


def main(args):
    if(len(args) < 3):
        print('Numero de Parametros Invalidos')
        sys.exit()

    host = args[1]
    porta = int(args[2])

    if len(args) > 3:
        idExibidor   = int(args[3])
        emissor = Emissor(host=host, porta=porta, idExibidor = idExibidor ) 
    else:
        emissor = Emissor(host=host, porta=porta)
    emissor.iniciar()



if __name__ == "__main__":
    main(sys.argv)