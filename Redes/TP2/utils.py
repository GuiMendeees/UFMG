import binascii
import re

def encode16(s):
    return binascii.hexlify(s)

def decode16(s):
    return binascii.unhexlify(s)

def extraiQuadro(x):
    x = x.hex()
    #print(x)
    return [ord(c) for c in x]

def extraiTamanhoQuadro(msgDecod):
    quadro = extraiQuadro(msgDecod)
    lenghtQuadro = quadro[16:20]
    #print("Lenght dentro da função",lenghtQuadro)
    strTam = ''
    for i in lenghtQuadro:
        strTam += chr(i)
    regex = "^0+(?!$)"
    strTam = re.sub(regex, "", strTam)
    lenght = 0
    try:
        lenght = int(strTam, 16)
    except ValueError:
        pass      
    if lenght != 0:
        return lenght

def validaMensagem(msgDecod):
    #Avalia o checksum da mensagem
    return True

def checksum(msgBytes):
    return int(b'%02X' % (sum(msgBytes) & 0xFF),16)