#ifndef DECK_H_
#define DECK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
  *enum kind_e - kind of card, the enum assigns int values to
  *its enumerators by default from 0 if explicit values aint
  *defined
  *
  *@SPADE: 1st kind
  *@HEART: 2nd kind
  *@CLUB: 3rd kind
  *@DIAMOND: 4th kind
  */

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;


void sort_deck(deck_node_t **deck);
int collate_cards(const void *a, const void *b);
#endif
