import gmpy2
import binascii
n=
p=gmpy2.mpz()
q=gmpy2.mpz()
c=gmpy2.mpz()
e=gmpy2.mpz()
phi_n=(p-1)*(q-1)
d=gmpy2.invert(e,phi_n)
m=pow(c,d,n)
#print("十进制:\n%s"%m)
m_hex=hex(m)[2:]    #[2:]把0x切了
#print("十六进制:\n%s"%(m_hex))
print(binascii.a2b_hex(m_hex).decode("utf-8")) #a2b_hex用于十六进制转字符串
