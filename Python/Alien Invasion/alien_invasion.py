import sys
import pygame
from settings import Settings
from ship import Ship
import game_functions as gf

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

        gf.check_events()

        # 每次循环都重绘屏幕
        screen.fill(bg_color)
        ship.blime()

        pygame.display.flip()

run_game()
