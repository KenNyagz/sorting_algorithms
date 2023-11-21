#include "deck.h"

/**
  *collate_cards - This is a helper function that qsort will use to sort
  *the cards in an array. It compares cards based on kind and value as
  *depicted by the strutcs given
  *
  *@a: 1st parameter to compare against
  *@b: 2nd parameter to compare with
  *
  *Return: returns an int value that qsort uses to either place the parameter
  *before x (ascending - return x - y) or before y (descending - return y - x)
  */
int collate_cards(const void *a, const void *b)
{
	deck_node_t *card_a = *(deck_node_t **)a;
	deck_node_t *card_b = *(deck_node_t **)b;
	const char *values[] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};
	int x, y, i;

	if (card_a->card->kind < card_b->card->kind)
		return (-1);
	else if (card_a->card->kind > card_b->card->kind)
		return (1);
	/*compare values if kinds are equal*/
	for (i = 0; i < 13; ++i)
	{
		if (strcmp(card_a->card->value, values[i]) == 0)
			x = i;
		if (strcmp(card_b->card->value, values[i]) == 0)
			y = i;
	}
		return (x - y);

}

/**
  *sort_deck - sorts a deck of cards from Ace to King, from Spades to Diamonds
  *
  *@deck: doubly linked list containg the unsorted cards
  */

void sort_deck(deck_node_t **deck)
{
	/* Create an array from the linked list for sorting*/
	deck_node_t **deck_array;
	deck_node_t *current = *deck;
	size_t deck_size = 0, i;

	while (current != NULL)
	{
		++deck_size;
		current = current->next;
	}

	deck_array = (deck_node_t **)malloc(deck_size * sizeof(deck_node_t *));
	if (deck_array == NULL)
	{
		exit(EXIT_FAILURE);
	}

	current = *deck;
	for (i = 0; i < deck_size; ++i)
	{
		deck_array[i] = current;
		current = current->next;
	}

	/* Now use the qsort to sort the array*/
	qsort(deck_array, deck_size, sizeof(deck_node_t *), collate_cards);

	/*Reconstruct the linked list with the sorted nodes*/
	for (i = 0; i < deck_size - 1; ++i)
	{
		deck_array[i]->next = deck_array[i + 1];
		deck_array[i + 1]->prev = deck_array[i];
	}

	deck_array[0]->prev = NULL;
	deck_array[deck_size - 1]->next = NULL;

	*deck = deck_array[0];

	free(deck_array);
}
