#include "Game.h"
#include "Engine.h"
#include "Enemy.h"
#include "Pause.h"
#include "Save.h"
#include "Ranking.h"
#include "GameResult.h"
#include "Destroy.h"
#include "Bonus.h"
#include "PlayerName.h"
#include <vector>

using namespace std;

Game Game::instance = Game();

Game& Game::getInstance() {
	return instance;
}

Game::Game() {
	srand(time(0));
	background = al_load_bitmap("game_background.png");
	bullet = al_load_bitmap("bullet.png");
	crosshair = al_load_bitmap("crosshair.png");
	score = 0;
	playerName = "";
	bullets = 7;
	remainingTime = 90;
	counter = 0;

	al_reserve_samples(2);
	gameMusic = al_create_sample_instance(al_load_sample("gameMusic.ogg"));
	al_set_sample_instance_playmode(gameMusic, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(gameMusic, al_get_default_mixer());
	al_set_sample_instance_gain(gameMusic, 0.1);

	shootEffect = al_create_sample_instance(al_load_sample("shootEffect.ogg"));
	al_set_sample_instance_playmode(shootEffect, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(shootEffect, al_get_default_mixer());

	bonus1.push_back(al_load_bitmap("bonus1_1.png"));
	bonus1.push_back(al_load_bitmap("bonus1_2.png"));
	bonus1.push_back(al_load_bitmap("bonus1_3.png"));
	bonus1.push_back(al_load_bitmap("bonus1_4.png"));

	bonus2.push_back(al_load_bitmap("bonus2_1.png"));
	bonus2.push_back(al_load_bitmap("bonus2_2.png"));
	bonus2.push_back(al_load_bitmap("bonus2_3.png"));
	bonus2.push_back(al_load_bitmap("bonus2_4.png"));

	enemyAnimationLeft = Animation(0.05);
	enemyAnimationLeft.addBitmap("left_1.png");
	enemyAnimationLeft.addBitmap("left_2.png");
	enemyAnimationLeft.addBitmap("left_3.png");
	enemyAnimationLeft.addBitmap("left_4.png");
	enemyAnimationLeft.addBitmap("left_5.png");
	enemyAnimationLeft.addBitmap("left_6.png");
	enemyAnimationLeft.addBitmap("left_7.png");
	enemyAnimationLeft.addBitmap("left_8.png");

	enemyAnimationRight = Animation(0.05);
	enemyAnimationRight.addBitmap("right_1.png");
	enemyAnimationRight.addBitmap("right_2.png");
	enemyAnimationRight.addBitmap("right_3.png");
	enemyAnimationRight.addBitmap("right_4.png");
	enemyAnimationRight.addBitmap("right_5.png");
	enemyAnimationRight.addBitmap("right_6.png");
	enemyAnimationRight.addBitmap("right_7.png");
	enemyAnimationRight.addBitmap("right_8.png");

	specialEnemyAnimationRight = Animation(0.05);
	specialEnemyAnimationRight.addBitmap("gentleman_right_2.png");
	specialEnemyAnimationRight.addBitmap("gentleman_right_2.png");
	specialEnemyAnimationRight.addBitmap("gentleman_right_3.png");
	specialEnemyAnimationRight.addBitmap("gentleman_right_4.png");
	specialEnemyAnimationRight.addBitmap("gentleman_right_5.png");
	specialEnemyAnimationRight.addBitmap("gentleman_right_6.png");
	specialEnemyAnimationRight.addBitmap("gentleman_right_7.png");
	specialEnemyAnimationRight.addBitmap("gentleman_right_8.png");
	specialEnemyAnimationRight.addBitmap("gentleman_right_9.png");
	specialEnemyAnimationRight.addBitmap("gentleman_right_10.png");
	specialEnemyAnimationRight.addBitmap("gentleman_right_11.png");
	specialEnemyAnimationRight.addBitmap("gentleman_right_12.png");
	specialEnemyAnimationRight.addBitmap("gentleman_right_13.png");
	specialEnemyAnimationRight.addBitmap("gentleman_right_14.png");
	specialEnemyAnimationRight.addBitmap("gentleman_right_15.png");
	specialEnemyAnimationRight.addBitmap("gentleman_right_16.png");
	specialEnemyAnimationRight.addBitmap("gentleman_right_17.png");

	specialEnemyAnimationLeft = Animation(0.05);
	specialEnemyAnimationLeft.addBitmap("gentleman_left_2.png");
	specialEnemyAnimationLeft.addBitmap("gentleman_left_2.png");
	specialEnemyAnimationLeft.addBitmap("gentleman_left_3.png");
	specialEnemyAnimationLeft.addBitmap("gentleman_left_4.png");
	specialEnemyAnimationLeft.addBitmap("gentleman_left_5.png");
	specialEnemyAnimationLeft.addBitmap("gentleman_left_6.png");
	specialEnemyAnimationLeft.addBitmap("gentleman_left_7.png");
	specialEnemyAnimationLeft.addBitmap("gentleman_left_8.png");
	specialEnemyAnimationLeft.addBitmap("gentleman_left_9.png");
	specialEnemyAnimationLeft.addBitmap("gentleman_left_10.png");
	specialEnemyAnimationLeft.addBitmap("gentleman_left_11.png");
	specialEnemyAnimationLeft.addBitmap("gentleman_left_12.png");
	specialEnemyAnimationLeft.addBitmap("gentleman_left_13.png");
	specialEnemyAnimationLeft.addBitmap("gentleman_left_14.png");
	specialEnemyAnimationLeft.addBitmap("gentleman_left_15.png");
	specialEnemyAnimationLeft.addBitmap("gentleman_left_16.png");
	specialEnemyAnimationLeft.addBitmap("gentleman_left_17.png");

	explosion = Animation(0.03);
	explosion.addBitmap("explosion1.png");
	explosion.addBitmap("explosion2.png");
	explosion.addBitmap("explosion3.png");
	explosion.addBitmap("explosion4.png");
}

Game::~Game() {
	al_destroy_bitmap(background);
	al_destroy_bitmap(bullet);
	al_destroy_bitmap(crosshair);
	al_destroy_sample_instance(gameMusic);
	al_destroy_sample_instance(shootEffect);
}

void Game::clearGame() {
	while (!e.empty())
		e.pop_back();
	while (!dstr.empty())
		dstr.pop_back();
	bonus = Bonus();
	score = 0;
	playerName = "";
	bullets = 7;
	remainingTime = 90;
	counter = 0;
}

void Game::loadGame(int score, string playerName, int bullets, int remainingTime) {
	while (!e.empty())
		e.pop_back();
	while (!dstr.empty())
		dstr.pop_back();
	bonus = Bonus();
	this->score = score;
	this->playerName = playerName;
	this->bullets = bullets;
	this->remainingTime = remainingTime;
	counter = 0;
}

int Game::mainLoop() {
	if (playerName.size() == 0)
		playerName = PlayerName::getInstance().mainLoop();
	if (playerName.size() != 0) {
		al_hide_mouse_cursor(Engine::getInstance().display);
		al_stop_sample_instance(Menu::getInstance().menuMusic);
		al_play_sample_instance(gameMusic);
		int mouse_x = -100;
		int mouse_y = -100;
		bool exit = false;
		ALLEGRO_EVENT_QUEUE* queue = Engine::getInstance().queue;
		ALLEGRO_EVENT event = Engine::getInstance().event;
		while (!exit) {
			if (event.type == ALLEGRO_EVENT_TIMER)
				draw(mouse_x, mouse_y);
			al_wait_for_event(queue, &event);
			if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
				if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				{
					al_show_mouse_cursor(Engine::getInstance().display);
					int current = Pause::getInstance().mainLoop();
					al_hide_mouse_cursor(Engine::getInstance().display);
					Save save = Save(score, playerName, bullets, remainingTime);
					switch (current) {
					case 1:
						save.saveToFile();
						break;
					case 2:
						exit = true;
						break;
					}
				}
				if (event.keyboard.keycode == ALLEGRO_KEY_R)
					reload();
			}
			if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && event.mouse.button & 2)
				reload();
			if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && event.mouse.button & 1)
				mouseClick(event.mouse.x, event.mouse.y);
			if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
				mouse_x = event.mouse.x;
				mouse_y = event.mouse.y;
			}
			if (remainingTime == 0)
				exit = true;
		}
		al_show_mouse_cursor(Engine::getInstance().display);
		GameResult::getInstance().mainLoop(score);
		al_play_sample_instance(Menu::getInstance().clickEffect);
		Ranking::getInstance().addSave(Save(score, playerName));
		al_stop_sample_instance(gameMusic);
		al_play_sample_instance(Menu::getInstance().menuMusic);
	}
	return 4;
}

void Game::draw(int mouse_x, int mouse_y) {
	counter++;
	if (counter == 60) {
		counter = 0;
		remainingTime--;
	}
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(background, 0, 0, 0);
	al_draw_textf(Engine::getInstance().big_font, al_map_rgb(0, 0, 0), 30, 30, 0, "Wynik: %d", score);
	al_draw_textf(Engine::getInstance().big_font, al_map_rgb(0, 0, 0), 30, 80, 0, "Pozostale naboje: %d", bullets);
	al_draw_textf(Engine::getInstance().big_font, al_map_rgb(0, 0, 0), 30, 130, 0, "Pozostaly czas: %d", remainingTime);
	for (int i = 0; i < bullets; i++)
		al_draw_bitmap(bullet, 50 + i * 50, 900, 0);
	if (bullets == 0)
		al_draw_textf(Engine::getInstance().big_font, al_map_rgb(0, 0, 0), 825, 540, 0, "Brak naboi");
	bonus.draw();
	if (e.empty())
		newEnemies();
	else
		for (int i = 0; i < (int)e.size(); i++) {
			if (e[i].direction)
				e[i].draw(e[i].x + 10, e[i].y);
			else
				e[i].draw(e[i].x - 10, e[i].y);
			if (e[i].x > Engine::getInstance().width + 300 || e[i].x < -300)
				e.erase(e.begin() + i);
		}
	for (int j = 0; j < dstr.size(); j++) {
		if (!dstr[j].draw())
			dstr.erase(dstr.begin() + j);
	}
	al_draw_bitmap(crosshair, mouse_x, mouse_y, 0);
	al_flip_display();
}

void Game::newEnemies() {
	int direction;
	int random = rand() % 10;
	if (random == 1) {
		direction = rand() % 2;
		if (direction)
			e.push_back(Enemy(direction, specialEnemyAnimationRight, SPECIAL));
		else
			e.push_back(Enemy(direction, specialEnemyAnimationLeft, SPECIAL));
	}
	random = rand() % 10;
	if (random == 1 && bonus.drawBonus == false) {
		random = 1 + rand() % 2;
		if (random == 1)
			bonus = Bonus(0.1, 4, bonus1);
		if (random == 2)
			bonus = Bonus(0.1, 4, bonus2);
	}
	for (int i = 0; i < rand() % 10; i++) {
		direction = rand() % 2;
		if (direction)
			e.push_back(Enemy(direction, enemyAnimationRight, NORMAL));
		else
			e.push_back(Enemy(direction, enemyAnimationLeft, NORMAL));
		for (int j = 0; j < (int)e.size() - 1; j++) {
			if (collision(e.back(), e[j])) {
				e.pop_back();
				i--;
				break;
			}
		}
	}
}

void Game::reload() {
	if (bullets > 0 && score > 0)
		score -= 10;
	bullets = 7;
}

void Game::mouseClick(int x, int y) {
	if (bullets > 0) {
		for (int i = 0; i < (int)e.size(); i++) {
			if (collision(e[i], x, y)) {
				dstr.push_back(Destroy(e[i].x, e[i].y, explosion, e[i].scale));
				score += e[i].score();
				e.erase(e.begin() + i);
			}
		}
		if (collision(bonus, x, y)) {
			dstr.push_back(Destroy(bonus.x - al_get_bitmap_width(bonus.bitmap[bonus.i]) / 2, bonus.y, explosion, 1.0));
			if (bonus.bitmap == bonus1)
				score += 20;
			if (bonus.bitmap == bonus2)
				if (remainingTime > 85)
					remainingTime = 90;
				else
					remainingTime += 5;
			bonus.drawBonus = false;
		}
		al_stop_sample_instance(shootEffect);
		al_play_sample_instance(shootEffect);
		bullets--;
	}
}

bool Game::collision(Enemy e, double x, double y)
{
	int w = al_get_bitmap_width(e.animation.bitmap[e.animation.i]);
	int h = al_get_bitmap_height(e.animation.bitmap[e.animation.i]);
	if (x > e.x && x < e.x + w && y  > e.y && y < e.y + h)
		return true;
	else
		return false;
}

bool Game::collision(Bonus b, double x, double y) {
	if (b.drawBonus) {
		int w = al_get_bitmap_width(b.bitmap[b.i]);
		int h = al_get_bitmap_height(b.bitmap[b.i]);
		x = x + w * 3 / 4;
		y = y + h * 1 / 4;
		if (x > b.x && x < b.x + w && y  > b.y && y < b.y + h)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool Game::collision(Enemy e1, Enemy e2)
{
	int h1 = al_get_bitmap_height(e1.animation.bitmap[e1.animation.i]);
	int h2 = al_get_bitmap_height(e1.animation.bitmap[e1.animation.i]);
	if (e1.y + h1 >= e2.y && e2.y + h2 >= e1.y)
		return true;
	else
		return false;
}