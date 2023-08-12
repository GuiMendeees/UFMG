from cliente import *

class Exibidor(Client):
    def __init__(self, host, porta):
        super(Exibidor, self).__init__(host, porta)

    def iniciar(self):
        if (self.conectar(0)):
            print('Digite CTRL+C para encerrar')

        else:
            print('Erro ao conectar')
            sys.exit()

        while True:
            # Lista de sockets conectados
            select.select([self.sock] , [], [])

            header = self.recebeHeader()
            if (not header):
                print('Desconectado')
                sys.exit()

            if (len(header) != 4):
                print('Erro no Header')
                sys.exit()

            tipoMensagemHeader, idOrigem, idDestino, seqNum = header

            if (tipoMensagemHeader == tipoMensagem["OK"]):
                pass

            elif (tipoMensagemHeader == tipoMensagem["ERRO"]):
                pass

            elif (tipoMensagemHeader == tipoMensagem["FLW"]):
                if (self.id != idDestino):
                    continue
                self.msgTipoFlw(idOrigem, idDestino)
                sys.exit(0)

            elif (tipoMensagemHeader == tipoMensagem["MSG"]):
                if (idDestino == self.id):
                    self.msgTipoMsg(idOrigem, seqNum)

            elif (tipoMensagemHeader == tipoMensagem["CREQ"]):
                pass

            elif (tipoMensagemHeader == tipoMensagem["CLIST"]):
                self.msgTipoClist()

            else:
                return

    def msgTipoOk(self, idOrigem, seqNum):
        self.seqNum += 1

    def msgTipoMsg(self, idOrigem, seqNum):
        try:
            length = struct.Struct('! H').unpack(self.receberMensagem(struct.Struct('! H').size))[0]
            structString = struct.Struct('! ' + str(length) + 's')
            msg = structString.unpack(self.receberMensagem(structString.size))[0]
        except:
            print('Erro ao receber mensagem')
            raise
        if (idOrigem == serverID):
            print(msg.decode('ascii'), end="")

        else:
            print('Mensagem {} do Emissor {}: '.format(seqNum+1, idOrigem)  + msg.decode('ascii'), end="")

  
        try:
            header = (tipoMensagem["OK"], self.id, idOrigem, seqNum)
            self.enviarMensagem(header)
        except:
            print('Erro ao enviar mensagem')
            raise

    def msgTipoClist(self):
        structAux = struct.Struct('! H')
        result = self.receberMensagem(structAux.size)
        length = structAux.unpack(result)[0]

        if (length > 0):
            struct_aux = struct.Struct('! ' + str(length) + 'H')
            result = self.receberMensagem(struct_aux.size)
            msg = struct_aux.unpack(result)

        print('IDs conectados:')
        for x in list(msg):
            print(x)

   
def main(args):
    if(len(args) < 3):
        print('Numero de Parametros Invalidos')
        sys.exit()

    host = args[1]
    porta = int(args[2])

    exibidor = Exibidor(host=host, porta=porta)
    exibidor.iniciar()


if __name__ == "__main__":
    main(sys.argv)
