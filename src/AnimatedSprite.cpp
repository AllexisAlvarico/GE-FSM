#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite() : 
	m_current_frame(0),
	m_timer(0.5f),
	m_loop(true),
	m_play_count(0),
	m_max_plays(0),
	m_played(false)
{
	DEBUG_MSG("AnimatedSprite()");
}

AnimatedSprite::AnimatedSprite(SDL_Texture* t_texture) : AnimatedSprite(){
	DEBUG_MSG("AnimatedSprite(const Texture&)");
	 m_texture = t_texture;
}

AnimatedSprite::AnimatedSprite(SDL_Texture* t_texture, const SDL_Rect& t_rect) : 
	AnimatedSprite(t_texture)
{
	DEBUG_MSG("AnimatedSprite(const Texture&, const IntRect&)");
	m_frames.push_back(t_rect);
}

AnimatedSprite::~AnimatedSprite() {
	DEBUG_MSG("~AnimatedSprite()");
}

const Timer& AnimatedSprite::getClock() {
	return m_clock;
}

const float AnimatedSprite::getTime() {
	return m_timer;
}

void AnimatedSprite::setTime(float t_timer)
{
	this->m_timer = t_timer;
}

const vector<SDL_Rect>& AnimatedSprite::getFrames() {
	return m_frames;
}

void AnimatedSprite::clearFrames() {
	m_current_frame = 0;
	m_played = false;
	if (!m_frames.empty())
	{
		m_frames.clear();
	}
}

void AnimatedSprite::setTextureRect(SDL_Rect t_rect)
{
	m_rect = t_rect;
}

const SDL_Rect& AnimatedSprite::getFrame(int t_n) {
	return m_frames[t_n];
}

void AnimatedSprite::addFrame(const SDL_Rect& t_frame) {
	m_frames.push_back(t_frame);
}

const int AnimatedSprite::getCurrentFrame() {
	return m_current_frame;
}

void AnimatedSprite::setLooped(bool loop) {
	this->m_loop = loop;
}

const bool AnimatedSprite::getLooped() {
	return this->m_loop;
}

void AnimatedSprite::setPlayed(bool t_played) {
	this->m_played = t_played;
}

const bool AnimatedSprite::getPlayed() {
	return this->m_played;
}

void AnimatedSprite::update(){
	// If not looped only play once
	if (m_played == true && !m_loop)
	{
		m_current_frame = m_frames.size() - 1;
	}
	else {
		if (m_clock.getTimer() > m_timer) {
			if (m_frames.size() > m_current_frame + 1)
			{
				m_current_frame++;
			}
			else {
				m_current_frame = 0;
				m_played = true;
			}
			m_clock.reset();
		}
	}
	
}

void AnimatedSprite::render(float x, float y, SDL_Renderer* t_renderer){

	SDL_FRect renderQuad = { x, y, static_cast<float>(m_rect.w), static_cast<float>(m_rect.h) };
	SDL_RenderCopyF(t_renderer, m_texture, &m_rect, &renderQuad);
}

