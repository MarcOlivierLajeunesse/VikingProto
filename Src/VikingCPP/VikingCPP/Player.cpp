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


// 2 versions of input. 
// 1. pure top-down, where the player can look and change directions using the mouse
// 2. top down with angle (kinda isometric), where the player only moves and attacks using the keyboard. The PC can only face in 4 discrete directions

//void Player::updateMotionFromInput() {
//	// version 1
//	motion = Vector2(0, 0);
//	Input* in = Input::get_singleton();
//	look_at(get_global_mouse_position());
//	if (in->is_action_pressed("move_forward")) {
//		//motion.y -= SPEED;
//		motion = Vector2(SPEED, 0).rotated(get_rotation());
//	}
//	if (in->is_action_pressed("move_back")) {
//		//motion.y += SPEED;
//		motion = Vector2(-SPEED, 0).rotated(get_rotation());
//	}
//	if (in->is_action_pressed("move_left")) {
//		//motion.x -= SPEED;
//		motion = Vector2(0, -SPEED).rotated(get_rotation());
//	}
//	if (in->is_action_pressed("move_right")) {
//		//motion.x += SPEED;
//		motion = Vector2(0, SPEED).rotated(get_rotation());
//	}
//}

void Player::updateMotionFromInput() {
	// version 2

	//TODO use states and sprite sheets to determine direction player is looking in
	motion = Vector2(0, 0);
	Input* in = Input::get_singleton();

	if (in->is_action_pressed("move_forward")) {
		//motion.y -= SPEED;
		//look_at(Vector2(0, -1));
		motion = Vector2(0, -SPEED);
	}
	if (in->is_action_pressed("move_back")) {
		//motion.y += SPEED;
		//look_at(Vector2(0, 1));
		motion = Vector2(0, SPEED);
	}
	if (in->is_action_pressed("move_left")) {
		//motion.x -= SPEED;
		//look_at(Vector2(-1, 0));
		motion = Vector2(-SPEED, 0);
	}
	if (in->is_action_pressed("move_right")) {
		//motion.x += SPEED;
		//look_at(Vector2(1, 0));
		motion = Vector2(SPEED, 0);
	}
}