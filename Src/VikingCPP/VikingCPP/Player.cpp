#include "Player.h"

using namespace godot;

void Player::_register_methods() {
	register_method("_process", &Player::_process);

}

void Player::_init() {

}

Player::Player() {
	motion = Vector2(0, 0);
}

Player::~Player(){}


void Player::_process(float delta) {
	updateMotionFromInput();
	move_and_slide(motion);
}

void Player::updateMotionFromInput() {
	motion = Vector2(0, 0);
	Input* in = Input::get_singleton();
	look_at(get_global_mouse_position());
	if (in->is_action_pressed("move_forward")) {
		//motion.y -= SPEED;
		motion = Vector2(SPEED, 0).rotated(get_rotation());
	}
	if (in->is_action_pressed("move_back")) {
		//motion.y += SPEED;
		motion = Vector2(-SPEED, 0).rotated(get_rotation());
	}
	if (in->is_action_pressed("move_left")) {
		//motion.x -= SPEED;
		motion = Vector2(0, -SPEED).rotated(get_rotation());
	}
	if (in->is_action_pressed("move_right")) {
		//motion.x += SPEED;
		motion = Vector2(0, SPEED).rotated(get_rotation());
	}
}