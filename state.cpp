#include "constants.h"
#include "stfu.h"

int initialize() { return STATE_SETUP; }

int wireBeingSetUp = 0;

int setupModule() { return STATE_SETUP; }

int ready() { return STATE_RUNNING; }

int running() { return STATE_RUNNING; }

int finished() { }
