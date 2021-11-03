#ifndef PLAYER_H
#define PLAYER_H
#include "Events.h"
#include "PlayerState.h"
#include "AnimatedSprite.h"

class Player
{
private:
	PlayerState* m_state;
	AnimatedSprite m_animated_sprite;

public:
	Player(const AnimatedSprite& t_sprite);
	virtual void handleInput(gpp::Events t_input);
	virtual void update();
	AnimatedSprite& getAnimatedSprite();
	AnimatedSprite& getAnimatedSpriteFrame();
	void setAnimatedSprite(AnimatedSprite& t_animated_sprite);
	PlayerState* getPlayerState();
	void setPlayerState(PlayerState* t_state);
	void render(SDL_Renderer* t_renderer);
};
#endif

