# Utilitaire pour la libc / libFT
libft et autre lib spliter pour un choix divers et varier.
## LibStr
La libStr permet de créer une chaine de caractère avec une capacité, elle garde toujours la plus grande allocation de ça capacité faite. La capacité augmente au besoin.
`

	t_str	*str = str_new("Salut bande de salope!!\n");
	str_put(str);
	// Set sans Alloc
	str_setchar(str, "jolie jolie\n");
	str_put(str);
	// Set avec Realloc
	str_setchar(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n");
	str_put(str);
	// Set + Join Sans Realloc
	str_setchar(str, "Hello ");
	str_joinchar(str, 1, "World!\n");
	str_put(str);
	// Join Avec Realloc
	str_joinchar(str, 2, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. ", "Integer rhoncus erat tristique, ornare augue sit amet, vulputate dolor. Suspendisse pretium odio in molestie dignissim. Maecenas et justo consectetur nulla accumsan tincidunt id id magna. Suspendisse ultricies dolor lorem, vitae gravida arcu maximus in. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Sed eget posuere odio, ut ultrices nulla. Duis condimentum, nunc sit amet euismod maximus, sapien nunc accumsan urna, id commodo lorem orci nec elit.\n");
	str_put(str);
	str_free(&str);

`
