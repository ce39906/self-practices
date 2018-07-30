#########################################################################
#-*- coding: utf-8 -*-
# File Name: log.py
# Author: carbon06
# mail: carbon06@163.com
# Created Time: 2017-05-03 22:26:44
#!/usr/bin/python
#########################################################################
import logging,os
class Logger:
    def __init__(self,path,clevel = logging.DEBUG,flevel = logging.DEBUG):
        self.logger = logging.getLogger(path)
        # logger 总等级开关
        self.logger.setLevel(logging.DEBUG)
        fmt = logging.Formatter('[%(asctime)s] - [%(filename)s]'
            '[line:%(lineno)d] - [%(levelname)s]: %(message)s')
        # 设置输出到终端的日志级别
        sh = logging.StreamHandler()
        sh.setFormatter(fmt)
        sh.setLevel(clevel)
        # 设置输出到文件的日志级别
        fh = logging.FileHandler(path)
        fh.setFormatter(fmt)
        fh.setLevel(flevel)

        self.logger.addHandler(sh)
        self.logger.addHandler(fh)

    def debug(self,message):
        self.logger.debug(message)

    def info(self,message):
        self.logger.info(message)

    def warn(self,message):
        self.logger.warn(message)

    def error(self,message):
        self.logger.error(message)

    def critical(self,message):
        self.logger.critical(message)

if __name__ == '__main__':
    loglc = Logger('loglc',logging.ERROR,logging.DEBUG)
    loglc.debug('this is a debug message')
    loglc.info('this is an info message')
    loglc.warn('this is a warning message')
    loglc.error('this is an error message')
    loglc.critical('this is a critical message')
