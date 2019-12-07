#include "node.hpp"

Node::Node(ELEM val) : data( val ), next( nullptr ) {
}

Node::Node(ELEM val, Node *following) : data( val ), next( following ) {
}

Node::~Node() {
}

Node *Node::upNext() {
	return next;
}

ELEM Node::get() {
	return data;
}
