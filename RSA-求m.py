import gmpy2
import binascii
n=807862607863494903203347547751222668477246136996519972166847
p=gmpy2.mpz(780900790334269659443297956843)
q=gmpy2.mpz(1034526559407993507734818408829)
c=gmpy2.mpz(6525071913169990474785757170304035615411828876052879070297)
e=gmpy2.mpz(65537)
phi_n=(p-1)*(q-1)
d=gmpy2.invert(e,phi_n)
m=pow(c,d,n)
#print("十进制:\n%s"%m)
m_hex=hex(m)[2:]
#print("十六进制:\n%s"%(m_hex))
print(binascii.a2b_hex(m_hex).decode("utf-8")) #a2b_hex用于十六进制转字符串
