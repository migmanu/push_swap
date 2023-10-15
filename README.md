# push_swap: A 42 School coding project

![](https://github.com/migmanu/push_swap/blob/main/push_swap_vid.gif)

`push_swap` is probably my favorite project so far. It was definitely a challenge for me and it taught me many important lessons. 
In the next paragraphs, I will share how I solved it and what was my experience.

## Mechanical Turk
I got my approach from this amazing article. From what I've seen, most people either do that or the Radix Sort approach. I went with this one because it promised much faster results. Which it definitely is.

The only different project I've seen so far is a variation of Mechanical Turk where you take an average of stack A and push the closest smaller number to stack B. It got, essentially, the same results as Mechanical Turk.

I'm not gonna go through the logic of this approach as it would be better to read [the original piece](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) written by its creator. However, the article only details the general solution to the problem, without going into any details on how to actually implement it.

I don't want to spoil other students' 42 path, but I will share a few insights on how I did it, what mistakes I made, and what I learned.

### What I could have done better

#### Input control
Even though I tried to be really deliberate about this project, and to lay down a general approach in advance, I made some newbie mistakes. Mainly in the input handling department. You can see by reading my code that I separated the functions that check for wrong input into too many different files. Some check it while it still is only a string, while others while it has already been allocated into the heap in the form of a linked list.

This resulted in some complications I could have avoided if I had been a bit more structured.

*I really suggest you check as much as possible BEFORE allocating any memory at all.* This will save you some frustrating headaches.

#### Memory management
I solemnly promise not to fall into this mistake again: *Do not allocate any memory if it's not necessary.* Make sure you ruled out the stack path before committing to the heap one. It just makes everything way easier down the line.

#### Confirmation bias
It is impossible to have a detailed plan for a project that involves concepts you yet do not fully understand. That does not mean you should not plan at all. I find that having some broad, written-down ideas on how to complete your project is a must. But this means that you need to *reconsider your plans and expectations as you get new knowledge.* I definitely wasted a couple of days trying to make my initial, inefficient, approach fit. Be open to reconsider, delete whole files and re-develop.

### How I did it

#### Time frame
The project took me about three weeks. A lot of that time was spent reading and watching videos about new concepts that were introduced by the project. Even if some of them did not directly apply or only concerned the bonus, which I did not do.

##### Peer learning
By this point, it should go without saying that this is a cornerstone of 42 and learning in general. I evaluated several `push_swap` projects and annoyed the evaluatees with lots of questions. I asked more advanced students for general and specific advice. I compared with other repos online. But what helped me the most, hands down, was sharing what I know with others.

Some students go over `push_swap` like it's nothing. Some, like me, consider it a cool and challenging project that teaches you a lot of important concepts. If you are the latter, I highly advise you not to work on this alone. Rely on your peers and help others as much as you can.

