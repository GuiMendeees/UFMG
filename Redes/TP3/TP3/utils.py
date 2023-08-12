import socket
import select
import sys
import struct
import binascii
import ctypes


# ID do servidor
serverID = 65535

class Header:
	struct = struct.Struct('! H H H H')

tipoMensagem = {
	"OK" : 1,
	"ERRO" : 2,
	"OI" : 3,
	"FLW" : 4,
	"MSG" : 5,
	"CREQ" : 6,
	"CLIST" : 7
}

tipoCliente = {
  "EMISSOR": 1,
  "EXIBIDOR": 2

}




