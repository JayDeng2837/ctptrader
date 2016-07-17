# -*- encoding=utf-8 -*-
#!/usr/bin/env python

import os
import re

class_pattern_spi = re.compile('class\s(\w+)\s')
class_pattern_api = re.compile('class\s\w+\s(\w+)\s')
method_pattern = re.compile("virtual\s(\w+)\s(\w+)\((.*)\)")

COMMON_H = 'common_macro.h'

CTP_INCLUDE_PATH = 'include/CTP'

CTP_H_Base = 'CTP'

output_api_dir = 'include/CCTPApi'

CTPCApi_H_Base = 'CCTPApi'

LC_PREFIX = 'LC'

FN = 'fn'

LC_SUFFIX = 'Impl'

FTDC_STR = 'Ftdc'

REG_PREFIX = 'Register'

LC_CTP_API = 'LC_CTP_API'

RegisterSpi = 'RegisterSpi'

pApi_name = 'pLC_Api'

pSpi_name = 'pLC_Spi'

Con_Path = 'con_path'

bIsUsingUdp = 'bIsUsingUdp'

bIsMulticast = 'bIsMulticast'

Md = 'MdApi'

Trader = 'TraderApi'

output_dir = 'src/Platform/CCTPApiImpl'

def gen_common_h() :
    if not os.path.exists(output_dir) :
        os.makedirs(output_dir)
    if not os.path.exists(output_api_dir) :
        os.makedirs(output_api_dir)
    file_object = open(os.path.join(output_api_dir, COMMON_H), 'w')
    try:
        file_object.write('''#ifndef _H_COMMON_MACRO_H_
#define _H_COMMON_MACRO_H_\n
#ifdef WIN32
#ifdef DLL_EXPORT
#define %s __declspec(dllexport)
#else
#define %s __declspec(dllimport)
#endif
#else
#define %s
#endif\n

#include<stdlib.h>

#ifndef __cplusplus
typedef enum {false = 0, true = 1} bool;
#endif

#endif\n''' % (LC_CTP_API, LC_CTP_API, LC_CTP_API))
        
#define SCR_PRINT(arg, ...)	    printf(arg, ##__VA_ARGS__)\n

#include<stdlib.h>

#endif\n''' % (LC_CTP_API, LC_CTP_API, LC_CTP_API))

    finally:
        file_object.close()
        
def get_class_info(ctp_api_file_name):
    file_object = open(os.path.join(CTP_INCLUDE_PATH, '%s.h' % ctp_api_file_name))
    try:
        all_the_text = file_object.read()
        api_start = all_the_text.rfind('class')
        match = class_pattern_spi.search(all_the_text, 0, api_start)
        if match :
            spi_class_name = match.group(1)
        else :
            spi_class_name = ''
        funcs_spi = method_pattern.findall(all_the_text, 0, api_start)
        match = class_pattern_api.search(all_the_text, api_start)
        if match :
            api_class_name = match.group(1)
        else :
            api_class_name = ''
        funcs_api = method_pattern.findall(all_the_text, api_start)
        return (spi_class_name, funcs_spi, api_class_name, funcs_api)
    finally:
        file_object.close()
        
def getSpiClassName(info):
    return info[0]

def getApiClassName(info):
    return info[2]

def get_api_short_name(ctp_api_file_name):
    pos = ctp_api_file_name.find(FTDC_STR)
    return str(ctp_api_file_name)[pos + len(FTDC_STR):]
        
def get_etiger_spi_class_name(info):
    return '%s%s' % (LC_PREFIX, getSpiClassName(info))

def get_api_impl_h_name(ctp_api_file_name):
    return '%s%s%s.hpp' % (LC_PREFIX, ctp_api_file_name, LC_SUFFIX)

def get_api_impl_cpp_name(ctp_api_file_name):
    return '%s%s%s.cxx' % (LC_PREFIX, ctp_api_file_name, LC_SUFFIX)
        
def get_FN_name(ctp_api_file_name, item_name):
    return '%s%s%s' % (FN, get_api_short_name(ctp_api_file_name), item_name)

def get_Register_Callback_Name(ctp_api_file_name, name):
    return '%s%s%sCallback' % (REG_PREFIX, get_api_short_name(ctp_api_file_name), name)

def get_api_interface_h_name(ctp_api_file_name):
    return '%s%s.h' % (LC_PREFIX, ctp_api_file_name)

def get_Api_Function_Name(ctp_api_file_name, name):
    return '%s%s' % (get_api_short_name(ctp_api_file_name), name)

def get_c_def_params(params):
    param_list = str(params).split(',')
    res_list = []
    for param in param_list:
        format_param = param.strip()
        idx = format_param.find('Field')
        if (idx >= 0) :
            res_list.append('struct ' + format_param)
        else :
            res_list.append(format_param)            
    return (', ').join(res_list)

def get_params(params):
    param_list = str(params).split(',')
    res_list = []
    for param in param_list:
        format_param = param.strip()
        format_param = format_param.replace('[]', '')
        idx = format_param.find('*') + 1
        if (idx >= 1) :
            res_list.append(format_param[idx:])
        else :
            idx = format_param.find(' ')
            res_list.append(format_param[idx:])
    return (', ').join(res_list)

def gen_api_impl_h(info, ctp_api_file_name):
    output_filename = get_api_impl_h_name(ctp_api_file_name)
    macro_name = output_filename.upper().replace('.', '_')
    h_output = open(os.path.join(output_dir, output_filename), 'w')
    try:
        h_output.write('''#ifndef %s\n#define %s\n#include "%s.h"\n#include "%s"\n\n'''
                       % (macro_name, macro_name, ctp_api_file_name, get_api_interface_h_name(ctp_api_file_name)))
        h_output.write('class %s : public %s\n{\nprivate:\n\n' % (get_etiger_spi_class_name(info), getSpiClassName(info)))
        for item in info[1]:
            h_output.write('\t%s m_%s;\n' % (get_FN_name(ctp_api_file_name, item[1]), get_FN_name(ctp_api_file_name, item[1])))
        h_output.write('\npublic:\n')
        for item in info[1]:
            h_output.write('\tvoid %s(%s _%s);\n' % (get_Register_Callback_Name(ctp_api_file_name, item[1]), get_FN_name(ctp_api_file_name, item[1]), get_FN_name(ctp_api_file_name, item[1])))
            
        h_output.write('\npublic:\n')
        for item in info[1]:
            h_output.write('\tvirtual %s %s(%s);\n' % (item[0], item[1], item[2]))
        
        h_output.write('\t%s();\n' % get_etiger_spi_class_name(info))
        h_output.write('\t~%s();\n' % get_etiger_spi_class_name(info))
        h_output.write('\n};\n\n')
        h_output.write('%s * Get%s(void * %s);\n\n' % (get_etiger_spi_class_name(info), get_etiger_spi_class_name(info), pSpi_name))
        h_output.write('%s * Get%s(void * %s);\n\n' % (getApiClassName(info), getApiClassName(info), pApi_name))
        h_output.write('#endif')
    finally:
        h_output.close()
    return output_filename

def gen_api_impl_cpp(info, ctp_api_file_name):
    h_output = open(os.path.join(output_dir, get_api_impl_cpp_name(ctp_api_file_name)), 'w')
    try:
        h_output.write('#include "%s"\n\n' % (get_api_impl_h_name(ctp_api_file_name)))
        h_output.write('%s * Get%s(void * %s)\n{\n' % (get_etiger_spi_class_name(info), get_etiger_spi_class_name(info), pSpi_name))
        h_output.write('\treturn (%s *)(%s);\n}\n\n' % (get_etiger_spi_class_name(info), pSpi_name))
        h_output.write('%s * Get%s(void * %s)\n{\n' % (getApiClassName(info), getApiClassName(info), pApi_name))
        h_output.write('\treturn (%s *)(%s);\n}\n\n' % (getApiClassName(info), pApi_name))
        
        h_output.write('%s::%s()\n{\n' % (get_etiger_spi_class_name(info), get_etiger_spi_class_name(info)))
        
        for item in info[1]:
            h_output.write('\t m_%s = NULL;\n' % (get_FN_name(ctp_api_file_name, item[1])))
        
        h_output.write('}\n\n')
        
        h_output.write('%s::~%s()\n{}\n\n' % (get_etiger_spi_class_name(info), get_etiger_spi_class_name(info)))
        
        for item in info[1]:
            h_output.write('void %s::%s(%s _%s)\n{\n'
                           % (get_etiger_spi_class_name(info), get_Register_Callback_Name(ctp_api_file_name, item[1]), get_FN_name(ctp_api_file_name, item[1]), get_FN_name(ctp_api_file_name, item[1])))
            h_output.write('\t m_%s = _%s;\n' % (get_FN_name(ctp_api_file_name, item[1]), get_FN_name(ctp_api_file_name, item[1])))
            h_output.write('}\n\n')
            
        for item in info[1]:
            h_output.write('%s %s::%s(%s)\n{\n' % (item[0], get_etiger_spi_class_name(info), item[1], item[2]))
            if (item[2] == '') :
                h_output.write('\t (*m_%s)();\n' % (get_FN_name(ctp_api_file_name, item[1])))
            else :
                h_output.write('\t (*m_%s)(%s);\n' % (get_FN_name(ctp_api_file_name, item[1]), get_params(item[2])))
            h_output.write('}\n\n')
        
    finally:
        h_output.close()

def gen_api_interface_h(info, ctp_api_file_name):
    output_filename = get_api_interface_h_name(ctp_api_file_name)
    macro_name = output_filename.upper().replace('.', '_')
    h_output = open(os.path.join(output_api_dir, output_filename), 'w')
    try:
#        h_output.write('''#ifndef %s\n#define %s\n#include "%s"\n#include "%sThostFtdcUserApiStruct.h"\n#include "%s%s.h"\n
#//define function pointers
#''' % (macro_name, macro_name, COMMON_H, CTP_INCLUDE_PATH, CTP_INCLUDE_PATH, ctp_api_file_name))

        h_output.write('#ifndef %s\n#define %s\n\n'% (macro_name, macro_name))
        h_output.write('#include "%s"\n' % COMMON_H)
        h_output.write('''\n#ifdef __cplusplus\nextern "C" {\n#endif\n\n''')
        h_output.write('#include "ThostFtdcUserApiStruct.h"\n\n//define function pointers\n')
        
        for item in info[1]:
            if item[2] == '' :
                h_output.write('typedef %s (* %s)();\n' % (item[0], get_FN_name(ctp_api_file_name, item[1])))
            else :
                h_output.write('typedef %s (* %s)(%s);\n' % (item[0], get_FN_name(ctp_api_file_name, item[1]), get_c_def_params(item[2])))
                
        h_output.write('\n//register callbacks\n')
        h_output.write('%s void * Create%s();\n' % (LC_CTP_API, '%s%s' % (LC_PREFIX, getSpiClassName(info))))
        h_output.write('%s void Release%s(void * * %s);\n' % (LC_CTP_API, '%s%s' % (LC_PREFIX, getSpiClassName(info)), pSpi_name))
        for item in info[1]:
            h_output.write('%s void %s(void * %s, %s pCallback);\n' % (LC_CTP_API, get_Register_Callback_Name(ctp_api_file_name, item[1]), pSpi_name, get_FN_name(ctp_api_file_name, item[1])))
        
        h_output.write('\n//api method porting\n')
        
        if get_api_short_name(ctp_api_file_name) == Md :
            h_output.write('%s void * Create%s(const char * %s, bool %s, bool %s);\n'
                           % (LC_CTP_API, '%s%s' % (LC_PREFIX, getApiClassName(info)), Con_Path, bIsUsingUdp, bIsMulticast))
        else :
            h_output.write('%s void * Create%s(const char * %s);\n'
                           % (LC_CTP_API, '%s%s' % (LC_PREFIX, getApiClassName(info)), Con_Path))
        h_output.write('%s void Release%s(void * * %s);\n' % (LC_CTP_API, '%s%s' % (LC_PREFIX, getApiClassName(info)), pApi_name))
        for item in info[3]:
            if item[1] == RegisterSpi :
                h_output.write('%s void %s(void * %s, void * %s);\n' % (LC_CTP_API, get_Api_Function_Name(ctp_api_file_name, item[1]), pApi_name, pSpi_name))
                continue
            if item[2] == '' :
                h_output.write('%s %s %s(void * %s);\n' % (LC_CTP_API, item[0], get_Api_Function_Name(ctp_api_file_name, item[1]), pApi_name))
            else :
                h_output.write('%s %s %s(void * %s, %s);\n' % (LC_CTP_API, item[0], get_Api_Function_Name(ctp_api_file_name, item[1]), pApi_name, get_c_def_params(item[2])))
        
        h_output.write('''\n#ifdef __cplusplus\n}\n#endif\n#endif\n''')
    finally:
        h_output.close()

def gen_api_interface_cpp(info, ctp_api_file_name):
    print 'ctp_api_file_name=', ctp_api_file_name
    output_filename = '%s%s.cxx' % (LC_PREFIX, ctp_api_file_name)
    h_output = open(os.path.join(output_dir, output_filename), 'w')
    try:
        h_output.write('''#include "%s"\n''' % (get_api_interface_h_name(ctp_api_file_name)))
        h_output.write('''#include "%s"\n\n''' % get_api_impl_h_name(ctp_api_file_name))
        
        #spi
        h_output.write('void * Create%s()\n{\n\treturn (void *)(new %s);\n}\n\n'
                       % ('%s%s' % (LC_PREFIX, getSpiClassName(info)), get_etiger_spi_class_name(info)))
        h_output.write('void Release%s(void * * %s)\n{\n\tif (*%s != NULL)\n\t{\n\t\tdelete *%s;\n\t\t*%s = NULL;\n\t}\n}\n\n'
                       % ('%s%s' % (LC_PREFIX, getSpiClassName(info)), pSpi_name, pSpi_name, pSpi_name, pSpi_name))
        for item in info[1]:
            h_output.write('void %s(void * %s, %s pCallback)\n' % (get_Register_Callback_Name(ctp_api_file_name, item[1]), pSpi_name, get_FN_name(ctp_api_file_name, item[1])))
            h_output.write('{\n\tif (%s != NULL)\n\t{\n\t\t(Get%s(%s))->%s(pCallback);\n\t}\n}\n'
                           % (pSpi_name, get_etiger_spi_class_name(info), pSpi_name, get_Register_Callback_Name(ctp_api_file_name, item[1])))
        
        #api
        if get_api_short_name(ctp_api_file_name) == Md :
            h_output.write('%s void * Create%s(const char * %s, bool %s, bool %s)\n{\n\treturn (void *)(%s::Create%s%s(%s, %s, %s));\n}\n\n'
                       % (LC_CTP_API, '%s%s' % (LC_PREFIX, getApiClassName(info)), Con_Path, bIsUsingUdp, bIsMulticast,
                          getApiClassName(info), FTDC_STR, get_api_short_name(ctp_api_file_name), Con_Path, bIsUsingUdp, bIsMulticast))
        else :
            h_output.write('%s void * Create%s(const char * %s)\n{\n\treturn (void *)(%s::Create%s%s(%s));\n}\n\n'
                       % (LC_CTP_API, '%s%s' % (LC_PREFIX, getApiClassName(info)), Con_Path,
                          getApiClassName(info), FTDC_STR, get_api_short_name(ctp_api_file_name), Con_Path))
            
        h_output.write('void Release%s(void * * %s)\n{\n\tif (*%s != NULL)\n\t{\n\t\tdelete *%s;\n\t\t*%s = NULL;\n\t}\n}\n\n'
                       % ('%s%s' % (LC_PREFIX, getApiClassName(info)), pApi_name, pApi_name, pApi_name, pApi_name))
        for item in info[3]:
            if item[1] == RegisterSpi :
                h_output.write('%s void %s(void * %s, void * %s)\n' % (LC_CTP_API, get_Api_Function_Name(ctp_api_file_name, item[1]), pApi_name, pSpi_name))
                h_output.write('{\n\tif (%s != NULL)\n\t{\n\t\t(Get%s(%s))->%s(Get%s(%s));\n\t}\n}\n\n'
                               %(pApi_name, getApiClassName(info), pApi_name, RegisterSpi, get_etiger_spi_class_name(info), pSpi_name))
                continue
            
            attach_1 = ''
            attach_2 = ''
            if item[0] != 'void' :
                attach_1 = 'return '
                attach_2 = '\n\treturn -1;'
                
            if item[2] == '' :
                h_output.write('%s %s %s(void* %s)\n' % (LC_CTP_API, item[0], get_Api_Function_Name(ctp_api_file_name, item[1]), pApi_name))
                h_output.write('{\n\tif (%s != NULL)\n\t{\n\t\t%s(Get%s(%s))->%s();\n\t}%s\n}\n\n'
                           % (pApi_name, attach_1, getApiClassName(info), pApi_name, item[1], attach_2))
            else :
                h_output.write('%s %s %s(void* %s, %s)\n' % (LC_CTP_API, item[0], get_Api_Function_Name(ctp_api_file_name, item[1]), pApi_name, get_c_def_params(item[2])))
                h_output.write('{\n\tif (%s != NULL)\n\t{\n\t\t%s(Get%s(%s))->%s(%s);\n\t}%s\n}\n\n'
                           % (pApi_name, attach_1, getApiClassName(info), pApi_name, item[1], get_params(item[2]), attach_2))        
    finally:
        h_output.close()
    return output_filename

def gen_ctp_api(ctp_api_file_name):
    info = get_class_info(ctp_api_file_name)
    gen_api_interface_h(info, ctp_api_file_name)
    gen_api_interface_cpp(info, ctp_api_file_name)
    gen_api_impl_h(info, ctp_api_file_name)
    gen_api_impl_cpp(info, ctp_api_file_name)
    return info
    
def get_msg_str(prefix, item):
    return '%s_%s' % (prefix, str(item).lstrip().rstrip().upper())#.lstrip('ON'))
    
def get_msg_str2(prefix, item):
    return '%s_%s' % (prefix, str(item).lstrip().rstrip().upper())
    
def gen_message_h(md_info, trader_info, start_message):
    h_output = open(os.path.join(output_api_dir, 'ctp_cmessage.h'), 'w')
    try:
        macro_name = '_CTP_CMESSAGE_'
        h_output.write('''#ifndef %s\n#define %s\n\n//CTP CMessageDef\n\nenum {\n''' % (macro_name, macro_name))
        
        count = 0
        for item in md_info[1] :
            if count == 0 :
                h_output.write('''\t%s = %d,\n\n''' % (get_msg_str("MD", item[1]), start_message))
            else:
                h_output.write('''\t%s,\n\n''' % get_msg_str("MD", item[1]))
            count += 1
            
        for item in trader_info[1] :
            h_output.write('''\t%s,\n\n''' % get_msg_str("TRADER", item[1]))
        
        #h_output.write('''\t%s\n\t//Other User New Added Messages...\n\n''' % 'MAX_CTP_CMESSAGE')
        
        #....
        
        h_output.write('''};\n\nenum {\n''')
        
        count = 0
        for item in md_info[3] :
            if count == 0 :
                h_output.write('''\t%s = %d,\n\n''' % (get_msg_str2("MD", item[1]), start_message + 1000))
            else:
                h_output.write('''\t%s,\n\n''' % get_msg_str2("MD", item[1]))
            count += 1
            
        for item in trader_info[3] :
            h_output.write('''\t%s,\n\n''' % get_msg_str2("TRADER", item[1]))
        
        h_output.write('''\t%s\n\t//Other User New Added Messages...\n\n''' % 'MAX_CTP_CMESSAGE')
        #....
        h_output.write('''};\n\n#endif''')
            
    finally:
        h_output.close()

if __name__ == '__main__':
    gen_common_h()
    info1 = gen_ctp_api('ThostFtdcMdApi')
    info2 = gen_ctp_api('ThostFtdcTraderApi')
    gen_message_h(info1, info2, 3000)
