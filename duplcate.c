int ALGO(int A[n]){
	bool d = false;
	for ( int i = 0; i < n; ++i ) {
		for ( int j = 0; j < n; ++j ) {
			if ( (i != j ) && (A[ i ] == A[ j ]) ) {
				d = true;
				break;
			}
		}
		if ( d ) {
		break;
		}
	}
}





