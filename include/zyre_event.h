/*  =========================================================================
    zyre_event.h - Parsing Zyre messages

    -------------------------------------------------------------------------
    Copyright (c) 1991-2013 iMatix Corporation <www.imatix.com>
    Copyright other contributors as noted in the AUTHORS file.

    This file is part of Zyre, an open-source framework for proximity-based
    peer-to-peer applications -- See http://zyre.org.

    This is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 3 of the License, or (at
    your option) any later version.

    This software is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this program. If not, see
    <http://www.gnu.org/licenses/>.
    =========================================================================
*/

#ifndef __ZYRE_EVENT_H_INCLUDED__
#define __ZYRE_EVENT_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _zyre_event_t zyre_event_t;

// @interface
#define ZYRE_EVENT_ENTER 0x1
#define ZYRE_EVENT_JOIN 0x2
#define ZYRE_EVENT_LEAVE 0x3
#define ZYRE_EVENT_EXIT 0x4
#define ZYRE_EVENT_WHISPER 0x5
#define ZYRE_EVENT_SHOUT 0x6

//  Destructor, destroys a Zyre message.
CZMQ_EXPORT void
    zyre_event_destroy (zyre_event_t **self_p);

// Wrapper for zyre_recv
CZMQ_EXPORT zyre_event_t *
    zyre_event_recv (zyre_t *self);

// Returns message command which can be used in
// swtich case with defines above.
CZMQ_EXPORT int
    zyre_event_cmd (zyre_event_t *self);

//  Return the sending peer's id
CZMQ_EXPORT char *
    zyre_event_peerid (zyre_event_t *self);

// Returns all headers or NULL
CZMQ_EXPORT zhash_t *
    zyre_event_headers (zyre_event_t *self);

//  Returns value of header attribute name from the message headers 
//  obtained by ENTER. Return NULL if no value was found.
CZMQ_EXPORT char *
    zyre_event_get_header (zyre_event_t *self, char *name);

//  Returns the group name that has been shouted 
CZMQ_EXPORT char *
    zyre_event_group (zyre_event_t *self);

//  Returns the actual message data without any Zyre meta data
CZMQ_EXPORT zmsg_t *
    zyre_event_data (zyre_event_t *self);

// Self test of this class
CZMQ_EXPORT void
    zyre_event_test (bool verbose);
// @end

#ifdef __cplusplus
}
#endif

#endif