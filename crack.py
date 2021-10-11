#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Author: Liu Dan 

import os
import zipfile


def crack():
    f = open('password.txt', 'w')
    zip_file = 'w.zip'
    with open('combcpp_allpass5.txt', 'r') as fd:
        for i in fd:
            try:
                with zipfile.ZipFile(zip_file) as z:
                    z.extractall(pwd=bytes(i.strip(), 'utf-8'))
                    print(f'password: {i.strip()}')
                    f.write(i)
                    break
            except Exception as e:
                pass
#                if not str(e).startswith('Bad password'):
#                    print(i, e)

    f.close()


alphanum = 'abcdefghijklmnopqrstuvwxyz0123456789'
def comb(password, idx, length, fd):
    if idx == length:
        return

    for i in alphanum:
        tmp = password + i
        comb(tmp, idx + 1, length, fd)
        fd.write(tmp + '\n')

def write_passcode():
    with open('comb.txt', 'w') as fd:
        comb('', 0, 8, fd)


crack()
