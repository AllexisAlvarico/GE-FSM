#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <SDL_image.h>
#include "Timer.h"
#include <vector>
#include "Debug.h"

using namespace std;

class AnimatedSprite {
public:
	AnimatedSprite();
	AnimatedSprite(SDL_Texture* t_texture);
	AnimatedSprite(SDL_Texture* t_texture, const SDL_Rect& t_rect);
	~AnimatedSprite();

	const Timer& getClock();
	const float getTime();
	const vector<SDL_Rect>& getFrames();
	void clearFrames();
	const SDL_Rect& getFrame(int t_n);
	void addFrame(const SDL_Rect& t_frame);
	const int getCurrentFrame();
	void setLooped(bool);
	const bool getLooped();
	void setPlayed(bool t_played);
	const bool getPlayed();
	void setTime(float t_timer);
	void setTextureRect(SDL_Rect t_rect);
	void render(float x, float y, SDL_Renderer* t_renderer);
	SDL_Texture* getTexture() {return m_texture;}
	void update();

	
private:
	Timer m_clock;
	float m_timer;
	vector<SDL_Rect> m_frames;
	SDL_Rect m_rectOfImage;
	SDL_Texture* m_texture;
	unsigned int m_current_frame;
	bool m_loop;
	unsigned int m_play_count;
	unsigned int m_max_plays;
	bool m_played;
};

#endif // !ANIMATED_SPRITE_H
