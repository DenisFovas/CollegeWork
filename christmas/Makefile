main:
	if [ -d ./out ]; then rm -rf ./out; fi
	mkdir ./out
	gcc main.c -o ./out/christmas -g
	
exec:	main
	./out/christmas

clean:
	rm ./out/christmas

.PHONY: main exec clean