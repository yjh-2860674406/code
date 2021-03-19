import sys
import pygame

def check_events() :
    for event in pygame.event.get() :
                # 遇到让程序退出的行为的时候关闭窗口,退出程序
                if event.type == pygame.QUIT :
                    sys.exit()
                # 刷洗窗口,只允许存在一个新的窗口