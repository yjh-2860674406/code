import sys
import pygame
from settings import Settings
from ship import Ship

def run_game():
    # 初始化背景设置
    pygame.init()
    # 初始化设置
    ai_settings = Settings()
    # 创建显示窗口
    screen = pygame.display.set_mode((ai_settings.screen_width, ai_settings.screen_height))
    # 窗口的名字
    pygame.display.set_caption("Alien Invasion")
    # 创建一个飞船
    ship = Ship(screen)
    # 设置背景色
    bg_color = (230,230,230) # 白色

    # 当有操作的时候(点击鼠标或键盘)
    while True :

        for event in pygame.event.get() :
            # 遇到让程序退出的行为的时候关闭窗口,退出程序
            if event.type == pygame.QUIT :
                sys.exit()
            # 刷洗窗口,只允许存在一个新的窗口

        # 每次循环都重绘屏幕
        screen.fill(bg_color)
        ship.blime()

        pygame.display.flip()

run_game()
