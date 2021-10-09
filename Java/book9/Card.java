package Java.book9;

enum Suit {
        DIAMONDS, CLUBS, HEARTS, SPADES
    }
enum Rank {
        DEUCE, THREE, FOUR, FIVE, SIX, 
        SEVEN, EIGHT, NINE, TEN, JACK, 
        QUEEN, KING, ACE
    }

public class Card {
    private Suit suit;
    private Rank rank;

    public Card (Suit suit, Rank rank) {
        this.suit = suit; this.rank = rank;
    }

    public Suit getSuit() {
        return suit;
    }

    public Rank getRank() {
        return rank;
    }

    public String toString() {
        return rank.toString() + ":" + suit.toString();
    }
}