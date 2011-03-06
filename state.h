/*
 * Copyright (C) 2011 Andrea Mazzoleni
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __STATE_H
#define __STATE_H

/****************************************************************************/
/* state */

/**
 * Global variable to identify if Ctrl+C is pressed.
 */
extern volatile int global_interrupt;

struct snapraid_state {
	int verbose; /**< Verbose output. */
	int force; /**< Forced dangerous operations. */
	unsigned block_size; /**< Block size in bytes. */
	char content[PATH_MAX]; /**< Path of the content file. */
	char parity[PATH_MAX]; /**< Path of the parity file. */
	tommy_array diskarr; /**< Disk array. */
};

void state_init(struct snapraid_state* state);

void state_done(struct snapraid_state* state);

void state_config(struct snapraid_state* state, const char* path, int verbose, int force);

/**
 * Read the state.
 */
void state_read(struct snapraid_state* state);

/**
 * Write the new state.
 */
void state_write(struct snapraid_state* state);

/**
 * Update the internal state to represent the new state.
 */
void state_scan(struct snapraid_state* state);

/**
 * Sync.
 */
void state_sync(struct snapraid_state* state, pos_t blockstart);

/**
 * Check.
 */
void state_check(struct snapraid_state* state, int fix, pos_t blockstart);

int state_progress(time_t* start, time_t* last, pos_t blockpos, pos_t blockmax, uint64_t count_block, uint64_t count_size);

#endif

