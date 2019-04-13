#-*- coding: utf-8 -*-
"""
File Name: hire_info_db.py
Author: ce39906
Mail: ce39906@163.com
Created Time: 2019-04-13 07:46:29
"""
from db import DB

class HireInfo:
    def __init__(self, board, date, cur_user_num, max_user_num, cur_post_num):
        self.board = board
        self.date = date
        self.cur_user_num = cur_user_num
        self.max_user_num = max_user_num
        self.cur_post_num = cur_post_num


class HireInfoDB(DB):
    def __init__(self):
        DB.__init__(self)
        self.table = 'hire_info'

    def insert(self, hire_info):
        query = ("insert into %s"
                "(board,date,cur_user_num,max_user_num,cur_post_num)"
                "values('%s','%s',%d, %d, %d)"
                ) % (self.table,hire_info.board, hire_info.date, hire_info.cur_user_num,
                hire_info.max_user_num, hire_info.cur_post_num)

        self.execute(query)

    def select_by_board(self, board, days):
        query = ("select * from %s "
                 "where board = '%s' and to_days(now()) - to_days(date) <= %d "
                ) % (self.table, board, days)
        res = self.execute(query)
        
        return res
