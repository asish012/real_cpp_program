Project Description
======
You arrive in your office at a publisher of technical journals one morning to receive an email from your boss ::

	We are getting lots of submissions in plain ASCII text from non-native English speakers these days, and though the content is great, the spelling is sometimes terrible, and we’d like some way of automatically checking the quality before the stuff goes through to our editors. We’d like to pass each submission through a program that will tell us how many errors there are, and print them out in context. We’d also like like to be able to have multiple special dictionaries for each journal that contain words that are commonly used technically in those journals, but which might not appear in a standard English dictionary.

	[ Original Tutorial: http://latedev.wordpress.com/2011/07/28/writing-a-real-c-program-part-1a/ ]

The end product would be a console program, who’s command line would look something like this :: 
	scheck [-n] [[-d special.dict] ...] [file ...]

where the -n option only prints the number of errors, and the -d option specifies a special dictionary. There can be more than one -d option. The checker checks the listed files (if none are specified it reads standard input) and produces output of the form ::
	article1.txt,2 errors
	article1.text,7,thre,perhaps thre is a reaction 
	article1.text,12,phiton,low-energy phiton is emitted

