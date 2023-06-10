levenshtein: levenshtein.cpp
	g++ -o $@ $<

clean:
	rm -f levenshtein
