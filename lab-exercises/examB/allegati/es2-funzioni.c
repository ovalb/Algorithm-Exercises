Node rfun( Node l ) {
	if ( l -> w[0] != '\0' && l -> w[1] == '\0' )
		return l;
	Node n = malloc( sizeof(struct node) );
	n -> w = ( l -> w ) + 1;
	n -> next = l;
	return rfun( n );		
}

Node crea( char *w ) {
	Node lista = malloc (sizeof(struct node) );
	lista -> w = w;
	lista -> next = NULL;
	return rfun( lista );
}

char *cfun( char *w, Node l ){
	if ( l -> next == NULL )
		return strcat( w, l -> w );

	return strcat( cfun( w, l -> next ), l -> w );
}
