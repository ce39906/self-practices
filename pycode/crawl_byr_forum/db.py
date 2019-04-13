#-*- coding: utf-8 -*-
"""
File Name: db.py
Author: ce39906
Mail: ce39906@163.com
Created Time: 2019-04-13 07:41:17
"""
import MySQLdb

class DB:
    def __init__(self):
        self.cnx = MySQLdb.connect(host='127.0.0.1',
                                   user='****', 
                                   passwd='******',
                                   db='crawl',
                                   port=8415)
        self.cursor = self.cnx.cursor()
    
    def execute(self,query):
        self.cursor.execute(query)
        self.cnx.commit()
        return self.cursor.fetchall()
