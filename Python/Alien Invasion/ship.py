import pygame

class Ship() :

    def __init__ (self, screen) :

        self.screen = screen

        # 加载飞船图像并获取其外接矩阵
        self.image = pygame.image.load("Alien Invasion\images\ship.bmp")
        self.rect = self.image.get_rect()
        self.screen_rect = screen.get_rect()

        # 将每艘新飞船放到屏幕底部中央
        self.rect.centerx = self.screen_rect.centerx
        self.rect.bottom = self.screen_rect.bottom

    def blime (self) :
        # 在指定位置绘制飞船
        self.screen.blit(self.image, self.rect)

