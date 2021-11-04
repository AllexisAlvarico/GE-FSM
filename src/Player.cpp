#include <stdio.h>
#include "Player.h"
#include <Events.h>
#include <IdlePlayerState.h>


Player::Player(const AnimatedSprite& t_sprite) : m_animated_sprite(t_sprite)
{
	// Set the Player to Default to IdlePlayer State 
	// and Enter that State
	m_state = new IdlePlayerState();
	m_state->enter(*this);
	// set positions
	m_position.x = 0.0f;
	m_position.y = 0.0f;
}

void Player::handleInput(gpp::Events t_input) {
	PlayerState * state = m_state->handleInput(t_input);

	if (state != NULL) {
		m_state->exit(*this);
		delete m_state;
		m_state = state;
		m_state->enter(*this);
	}
}

void Player::update() {
	m_animated_sprite.update();
	m_state->update(*this);
}

AnimatedSprite& Player::getAnimatedSprite() {
	return m_animated_sprite;
}

AnimatedSprite& Player::getAnimatedSpriteFrame() {
	int frame = m_animated_sprite.getCurrentFrame();
	m_animated_sprite.setTextureRect(m_animated_sprite.getFrame(frame));
	return m_animated_sprite;
}

void Player::setAnimatedSprite(AnimatedSprite& t_animated_sprite) {
	this->m_animated_sprite = t_animated_sprite;
}

PlayerState* Player::getPlayerState() { return this->m_state; }

void Player::setPlayerState(PlayerState* t_state) { this->m_state = t_state; }

void Player::render(SDL_Renderer* t_renderer){

	getAnimatedSpriteFrame().render(m_position.x, m_position.y, t_renderer);
}