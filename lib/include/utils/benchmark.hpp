#pragma once
/*
 * This file is part of Lydia.
 *
 * Lydia is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Lydia is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Lydia.  If not, see <https://www.gnu.org/licenses/>.
 */

static void escape(void *p) { asm volatile("" : : "g"(p) : "memory"); }

static void clobber() { asm volatile("" : : : "memory"); }

static const int BENCH_CUDD_UNIQUE_SLOTS = CUDD_UNIQUE_SLOTS;
static const int BENCH_CUDD_CACHE_SLOTS = CUDD_CACHE_SLOTS;
