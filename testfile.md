# Speak English to Me, The Secret World of Programmers
___
It feels sometimes like programmers and normal people speak a totally different language and use computers in totally different ways. Something that you can discuss with more-or-less any competent programmer or sysadmin is completely foreign to people outside of our world.
Here are a handful of examples I've come across.
# Test first level header
## "Why does it have to be so complicated? I just want to install a program"
I come across this oftentimes when I'm trying to get someone to use a fancy program that solves their problem exactly.
I tell them to execute the simple and easy step of running `$PACKAGE_MANAGER install $PROGRAM`, and they don't want to do it.

*"It's easy!"* I say.

*"All you need to do is open the terminal... oh yeah, you probably need to know how to do that... Anyway, once it's open all you need to do us run... Oh yeah, well you need to install the package manager"*

*"Well after you install the package manager, you just need to... oh yeah, They just updated it, and you need to change your path to..."*

*"Alright. Just go to https://$SOFTWARE, and then you can install it from there"*

## "What was wrong with Microsoft Word?"
I love markdown and write more-or-less all of my written word in it.
It's great.
You can easily add links and tables, headings, and put in whatever you want with a few HTML tags if you're feeling saucy.
Not only that, but you can render it out into pretty much any way people are used to viewing documents using something like [Pandoc](https://pandoc.org).
The problem comes when I wish to share the document.
Non-technical people I know don't know what to do with some `notes.md` file once they get it.
Their OS just gives them a "How do I open this" dialogue that lists off some unrelated programs. 
If I give them a compiled document, they just send me back their edits of the compiled document, so I now have to open up word or adobe or whatever and copy/paste it back into my original markdown file.

*"But Alas"* you say, *"All they need to do is edit it in any text editor"*

I send them a link to [Markdown Guide](https://markdownguide.org) and tell them to edit it in Microsoft Word, and I receive the same three questions every time.

*"Why do you want me to learn a programming language?"*, *"Is Microsoft Word what you mean by a text editor"*, and *"Why couldn't you just do this in something simple like Word?"*

I try and try to explain that this arcane system of monochrome text and rendering steps is **ACTUALLY** easier than editing in Microsoft Word, but my pleas fall on deaf ears.

## "Why would you do that in the command line? It's way easier using $Program"
There are a bunch of little things that come up that I will mention off-hand, and have someone question me about it.
I explain how simple it is to just `convert -density 300 input.pdf -resize 50% output.png`, and I'm met with a blank stare

*"But I'm not a hacker"*, they plead.

*"This should be a simple program"*

> And of course it **is** a simple program, but whenever the first step is opeing a terminal, it is no longer simple

## "Oh, you're a programmer, Can't you do $THING"
While I probably could do $THING given enough time and effort, it's not my specialty

*"But it's a Windows program"* The tears are welling up in their eyes, they plead *"Don't you work on Windows"*

*"First off,"* I reply, *"No. And second off, This thing you want me to do involves having a PHD level education in the field and deep knowledge of a language I've never heard of"*

*"Well, if you didn't want to help, you could have just said so"*

## "Can you help with my printer"
no

## What was the point of writing this post?
I don't know.
Sometimes I'm frustrated by these things and I become disappointed that I cannot come up with a way to convince people that the world works the way I think it does.
Other times, I think the solution lies in our hands.
Maybe with enough programming and user-interface design, we can make the tools that make our lives easier good enough to be used by the general public and make our ways known.
Sometimes I think that the public computing education should be completely overhauled to support workflows like mine.
___
> Maybe I just need to have a little more empathy (or is it sympathy?) for normal people.
