#include "queue.h"
#include "dll.h"
#include "music_player.h"
#include <stdio.h>
#include <stdlib.h>

playlist_t* create_playlist() // return a newly created doubly linked list
{
	// DO NOT MODIFY!!!
	playlist_t* playlist = (playlist_t*) malloc(sizeof(playlist_t));
	playlist->list = create_list();
	playlist->num_songs = 0;
	playlist->last_song = NULL;
	return playlist;
}

void delete_playlist(playlist_t* playlist) // delete the playlist
{
	// DO NOT MODIFY!!!
	delete_list(playlist->list);
	free(playlist);
}

music_queue_t* create_music_queue() // return a newly created queue
{
	// DO NOT MODIFY!!!
	return create_queue();
}

void clear_music_queue(music_queue_t* q) // clear the queue q
{	
	// DO NOT MODIFY!!!
	delete_queue(q);
}

void add_song(playlist_t* playlist, int song_id, int where) // TODO: add a song id to the end of the playlist
{
	switch(where){
		case -1:
			insert_front(playlist->list, song_id);
			break;
		case -2:
			insert_back(playlist->list, song_id);
			break;
		default:
			insert_after(playlist->list, song_id, where);
			break;
	}
	playlist->num_songs = size(playlist->list);
}

void delete_song(playlist_t* playlist, int song_id) // TODO: remove song id from the playlist
{	
	if(playlist->last_song && playlist->last_song->data == song_id) playlist->last_song = NULL;
	delete_node(playlist->list, song_id);
	playlist->num_songs = size(playlist->list);
}

song_t* search_song(playlist_t* playlist, int song_id) // TODO: return a pointer to the node where the song id is present in the playlist
{	
	return search(playlist->list, song_id);
}

void search_and_play(playlist_t* playlist, int song_id) // TODO: play the song with given song_id from the list(no need to bother about the queue. Call to this function should always play the given song and further calls to play_next and play_previous)
{
	song_t* s = search(playlist->list, song_id);
	if(s){
		play_song(s->data);
		playlist->last_song  = s;
	}
}

void play_next(playlist_t* playlist, music_queue_t* q) // TODO: play the next song in the linked list if the queue is empty. If the queue is not empty, play from the queue
{
	if(!playlist->last_song && !is_empty(playlist->list)){
		play_song(playlist->list->head->data);
		playlist->last_song = playlist->list->head;
	}
	else if(empty(q)){
		if(is_empty(playlist->list)) return;
		else{
			if(!playlist->last_song || !playlist->last_song->next){
				play_song(playlist->list->head->data);
				playlist->last_song = playlist->list->head;
			}
			else{
				play_song(playlist->last_song->next->data);
				playlist->last_song = playlist->last_song->next;
			}
		}
	}
	else{
		play_song(dequeue(q));
	}
}

void play_previous(playlist_t* playlist) // TODO: play the previous song from the linked list
{
	
	if(is_empty(playlist->list)){
		return;}
	else{
		
		if(!playlist->last_song || !playlist->last_song->prev){
			play_song(playlist->list->tail->data);
			playlist->last_song = playlist->list->tail;
		}
		else{
			play_song(playlist->last_song->prev->data);
			playlist->last_song = playlist->last_song->prev;
		}
	}	
	
}

void play_from_queue(music_queue_t* q) // TODO: play a song from the queue
{
	if(!empty(q)){
		play_song(dequeue(q));
	}

}

void insert_to_queue(music_queue_t* q, int song_id) // TODO: insert a song id to the queue
{
	enqueue(q, song_id);
}

void reverse(playlist_t* playlist) // TODO: reverse the order of the songs in the given playlist. (Swap the nodes, not data)
{
	if(is_empty(playlist->list)) return;
	song_t* trav = playlist->list->head->next;
	song_t* curr = NULL;
	playlist->list->tail = playlist->list->head;
	while(trav){
		curr = trav;
		trav = trav->next;
		curr->prev->next = curr->next;
		if(curr->next) curr->next->prev = curr->prev;
		curr->next = playlist->list->head;
		curr->prev = NULL;
		playlist->list->head->prev = curr;
		playlist->list->head = curr;
	}		
}

void k_swap(playlist_t* playlist, int k) // TODO: swap the node at position i with node at position i+k upto the point where i+k is less than the size of the linked list
{
	song_t* trav = playlist->list->head;
	song_t* swap = trav;
	if(k>playlist->num_songs) return;
	for(int i=0; i<k; i++){
		swap = swap->next;
	}
	while(swap){
		trav->next->prev = swap;
			if(trav==playlist->list->head){
				playlist->list->head = swap;
			} else{
				trav->prev->next = swap;
			}
			song_t* snext = swap->next;
			song_t* sprev = swap->prev;
			swap->next = trav->next;
			swap->prev = trav->prev;
			if(swap == playlist->list->tail){
				playlist->list->tail = trav;
			} else{
				snext->prev = trav;	
			}
			sprev->next = trav;
			trav->next = snext;
			trav->prev = sprev;
			
			
			song_t* temp = trav;
			trav=swap->next;
			swap=temp->next;
	}
}

void shuffle(playlist_t* playlist, int k) // TODO: perform k_swap and reverse
{
	if(!is_empty(playlist->list)){
		k_swap(playlist, k);
		reverse(playlist);
	}
}

song_t* debug(playlist_t* playlist) // TODO: if the given linked list has a cycle, return the start of the cycle, else return null. Check cycles only in forward direction i.e with the next pointer. No need to check for cycles in the backward pointer.
{	
	song_t* tar = playlist->list->tail;
	return tar->next;
}

void display_playlist(playlist_t* p) // Displays the playlist
{
	// DO NOT MODIFY!!!
	display_list(p->list);
}

void play_song(int song_id)
{
	// DO NOT MODIFY!!!
	printf("Playing: %d\n", song_id);
}

