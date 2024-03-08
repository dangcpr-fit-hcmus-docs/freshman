import pygame, sys, random
from pygame.locals import *
pygame.init()

FPS = 60
screen = pygame.display.set_mode((500,400))
pygame.display.set_caption("Rắn săn mồi")
running=True
game_close=False
RED = (255,0,0)
GREEN = (0,255,0)
WHITE = (255,255,255)
BLACK = (0,0,0)
snake_x = 10
change_x = 0
snake_y = 10
change_y = 10
length = 15

font = pygame.font.SysFont('Times New Roman', 20) #Khai báo font chữ
food_x = random.randrange (10,490,10) # Toạ độ x của con mồi
food_y = random.randrange (10,390,10) # Toạ độ y của con mồi
def message(msg): # Hàm thông báo
    mess = font.render(msg, True, WHITE, BLACK)
    screen.blit(mess, (120, 100))
def vonglapgame():
    pass
def tangcd (cdran):
    for i in cdran:
        
chuyendong = pygame.time.Clock()
while running:
    while game_close == True: #Nếu như thua
        screen.fill(WHITE)
        message ('Bạn đã thua') #In ra màn hình message
        pygame.display.update()
        for event in pygame.event.get(): 
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_f:#Nếu nhấn phím f thì đóng cửa sổ game
                    running = False
                    game_close = False
                if event.key == pygame.K_s:#Nếu nhấn phím s thì game bắt đầu lại
                    pass
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
                running = False #Nếu nhấn dấu "X" thì đóng cửa sổ game
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                    change_x = -10
                    change_y = 0
            elif event.key == pygame.K_RIGHT:
                    change_x = 10
                    change_y = 0
            elif event.key ==  pygame.K_UP:
                    change_y = -10
                    change_x = 0
            elif event.key == pygame.K_DOWN:
                    change_y = 10
                    change_x = 0

    snake_x += change_x
    snake_y += change_y
    screen.fill(BLACK)
    pygame.draw.rect(screen, GREEN, (snake_x, snake_y, 10, 10)) #Vẽ con rán
    pygame.draw.rect(screen, RED, (food_x, food_y, 10, 10))
    if food_x == snake_x and food_y == snake_y:
        food_x = random.randrange (10,490,10) # Toạ độ x của con mồi
        food_y = random.randrange (10,390,10) # Toạ độ y của con mồi
        pygame.draw.rect(screen, RED, (food_x, food_y, 10, 10))
    pygame.display.update()
    chuyendong.tick(15)
pygame.quit()