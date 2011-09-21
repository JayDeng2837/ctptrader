'''
Created on 2011-9-21

@author: root
'''
from ctypes import *
import os 
cwd = os.getcwd()
print 'cwd=' + cwd
thostmduserapi = cdll.LoadLibrary(cwd + '/thostmduserapi.so')
thosttraderapi = cdll.LoadLibrary(cwd + '/thosttraderapi.so')  
#thostmduserapi = CDLL(cwd + '/thostmduserapi.so')
#thosttraderapi = CDLL(cwd + '/thosttraderapi.so')  
