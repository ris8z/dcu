#!/usr/bin/env python3

def hash_code(string):
    # (1 << 32) sposti 1 32 posti a sinsitra quindi il numero in bin sara' uno con 32 zeri dopo
    # se a questo gli leviamo uno avremo uno zero con 32 uno dopo, quindi esattamente 32 uno
    mask = (1 << 32) - 1

    h = 0
    for char in string:
        #(h & mask) ti ri da h assicurandosi che e' delle stesse dimensioni di mask, perche' se in un iterazione
        # >> (32 - 5) shifta tutti i bit a sinistra 32 - 5 volte, in questo modo i primi 5 bit a sinistra
        # si ritorovano a destra
        #11111 000000000000000000000
        #000000000000000000000 11111
        first_five_bits = (h & mask) >> (32 - 5)

        #shifiti 5 volte a sinistra tutti i bit e ti assicuri che sia sempre di 32 bit
        #saranno (32 - 5) random bit e 5 zero finali
        #11111111111111111111 00000
        h = (h << 5) & mask


        #addesso h diventa h or first_five_bits in questo modo avremo h e gli ultimi 5 zeri saranno i sui
        #primi 5 bits
        h = h | first_five_bits

        #addi ad h ascii value del char
        h += ord(char)

    return h

print(hash_code("hello"))
print(hash_code("Cat"))
