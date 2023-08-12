import sys
import socket
import struct
import base64
import utils as fun

## Endereco IP do Servidor
host = '127.0.0.1'

##Tamanho do Buffer
max_size = 1024

##Valor do SYNC
sync = 0xdcc023c2
syncBytes = sync.to_bytes(4,'big')

lenghtGlobal = 0

#####-------------------Cliente 
if sys.argv[1] == '-c':
    #print("Entrou no Cliente")

    ######################################-- Configurando Conexão   
    ip = sys.argv[2]
    porta = sys.argv[3]
    arq_input = sys.argv[4]
    arq_output = sys.argv[5]
    
   
    tcpCliente = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    dest = (host, int(porta))
    tcpCliente.connect(dest)
   
    ############################################################
    
    #Abrindo Arquivo de Input
    #print("Abrindo arquivo")
    with open(arq_input) as arq:
        line = arq.readline()
        #print("Arquivo Aberto")
        
    
    lines = []
    with open(arq_input,'r') as f:
        lines = f.readlines()
    
    f.close()

    li = 0 
    msg = lines[li]
        

    while (msg != '\x18' and (li < len(lines))):

        #Flags
        flags = 00
        flagsBytes = flags.to_bytes(4,'big')

        #ID Pacote
        id = 00
        idBytes = id.to_bytes(4,'big')
        
        #----Tamanho da Mensagem em int
        lenght = len(msg)

        #----Tamanho da Mensagem em Base16
        #lenghtBase16 = str(hex(len(msg)))
        
        #----Mensagem codificada em Base16
        msgBytes = str.encode(msg)

        #Valor do Checksum
        chk = 00
        
        #Enquandramento de Mensagem
        pctTemp = struct.pack(f'>4s 4s H H B B {lenght}s',syncBytes,syncBytes,lenght,chk,id,flags,msgBytes)

        #Condificação do Pacote Temporario para Base 16
        pctTemp16Bytes = fun.encode16(pctTemp)

        #Calculo do Checksum do Pacote
        chk = fun.checksum(pctTemp16Bytes)
       
        #Pacote definitivo para envio
        pctDef = struct.pack(f'>4s 4s H H B B {lenght}s',syncBytes,syncBytes,lenght,chk,id,flags,msgBytes)

        #Codificação do Pacote Definitivo para Base 16
        pctDef16Bytes = fun.encode16(pctDef)

        #Envio do Pacote
        tcpCliente.send (pctDef16Bytes)
        outPutSClient = open(arq_output, "w")
        outPutSClient.write(pctDef16Bytes.decode('utf-8'))
        outPutSClient.close()


        #---- Retorno do Servidor
        retornoServer = tcpCliente.recv(max_size)
        #struct.unpack("4i",retornoServer)
        #print(retornoServer)
        #print('retorno ', str.decode(retornoServer))
        msg = lines[li]
        li+=1

    tcpCliente.close()

    
#####------------------Servidor
if sys.argv[1] == '-s':
    #print("Entrou no Servidor")
    ######################################-- Configurando Conexão   
   
    porta = sys.argv[2]
    arq_input = sys.argv[3]
    arq_output = sys.argv[4]
    
    tcpServer = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    orig = (host, int(porta))
    tcpServer.bind(orig)
    tcpServer.listen(1)

    ############################################################

    while True:
        con, cliente = tcpServer.accept()
        #print ('Conectado por ', cliente)
        bytesRecebidos = 0
        while True:
            msg = con.recv(max_size)
            msgDecod = fun.decode16(msg)
            lenghtQuadro = fun.extraiTamanhoQuadro(msgDecod)
            #print(lenghtQuadro)
            try:
                pacote = struct.unpack_from(f'>4s 4s H H B B {lenghtQuadro}s', msgDecod)
            except:
                pass

            outPutServer = open(arq_output, "w")
            outPutServer.write(pacote[-1].decode('utf-8'))
            outPutServer.close()

            if (fun.validaMensagem(msgDecod) == True):
                confirm = struct.pack(">i", 1)
                #--Envio ao Cliente
                con.sendall(confirm)

            else:
                #--Envio ao Cliente
                con.sendall(confirm)
                confirm = struct.pack(">i", 0)
            
           
            
            if not msg:
                break
            
        #print ('Finalizando conexao do cliente', cliente)
        con.close()
    