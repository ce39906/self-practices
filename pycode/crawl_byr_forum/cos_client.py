#-*- coding: utf-8 -*-
"""
File Name: cos_client.py
Author: ce39906
Mail: ce39906@163.com
Created Time: 2019-04-12 15:54:31
"""
from qcloud_cos import CosConfig
from qcloud_cos import CosS3Client
import sys
import logging

class TencentCloudClient:
    def __init__(self):
        secret_id = '***************************'
        secret_key = '*****************'  
        region = 'ap-beijing'     
        token = None            
        scheme = 'https'  
        config = CosConfig(Region=region,
                           SecretId=secret_id,
                           SecretKey=secret_key,
                           Token=token,
                           Scheme=scheme)
        self.client = CosS3Client(config)
        self.url_prefix = 'https://myblog-********.cos.ap-beijing.myqcloud.com/'

    def upload_file(self, filename):
        self.client.put_object_from_local_file(Bucket='myblog-*******',
                                               LocalFilePath=filename,
                                               Key=filename,
                                               EnableMD5=False)

