# BA Thesis - Benjamin Ansohn McDougall

[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://GitHub.com/Naereen/StrapDown.js/graphs/commit-activity)
[![GPLv3 license](https://img.shields.io/badge/License-GPLv3-blue.svg)](http://perso.crans.org/besson/LICENSE.html)

![ToniGoesGreen](https://user-images.githubusercontent.com/81431370/177205837-97e28c38-7010-4a99-8066-b071fa82ef17.png)

## Toni Goes Green

## Description
Let people know what your project can do specifically. Provide context and add a link to any reference visitors might be unfamiliar with. A list of Features or a Background subsection can also be added here. If there are alternatives to your project, this is a good place to list differentiating factors.

## Visuals
Depending on what you are making, it can be a good idea to include screenshots or even a video (you'll frequently see GIFs rather than actual videos). Tools like ttygif can help, but check out Asciinema for a more sophisticated method.

## Roadmap

Many people enjoyed the game and its design, but they would have liked to see some kind of mini-game or a change in how the player character is controlled, e.g.  to be able to roam the diorama more freely from the perspective of a third-person.
This would add a unique touch to the game as well as offering a more diverse experience.
Furthermore, more levels were requested and some kind of leader-board or social aspect, which the game is lacking as of today.
This could be remedied by implementing real achievements in the play store or an actual ranking system.
Another improvement would be to persist the achieved level goals.
In the current implementation, each play-through displays the achievements reached, but they are not persisted in any way. By serialising the rewards, collecting them would be more appealing and motivate the players to obtain them all.
Also, the puzzles should be made more difficult, which was the intention for further development.
Another idea was that with more puzzles and the creation of more levels, more environmental tasks and topics should also be added to the player's active tasks, in addition to the ones already implemented.
Some ideas were: a mini game at the hot-dog stand in second level and to display the ecological footprint of each product offered instead of just stating that vegetarian food is always better for the environment, as is the current situation. 
Or mobility and transport levels actively showing the benefits of using a bicycle to travel shorter distances and how high the difference in emissions is compared to travelling by motorised vehicle.

Fixing the bug in the sixth level's ending is also on the agenda for further development.
As is a refactoring of the BP\_Node and maybe moving some of the blueprints and events to C++ classes in order to remove the problematic source control issues.
The blueprints should not contain foundational code that does not address functionality.
This would also give game, graphic and level designers more freedom in their use of blueprints and would ensure that the developers would not interfere in their work.
A good example of how that was implemented can be seen in the Match 3 game example depicted in \cref{fig:match3}.

## Contributing

The project is in a private Github repository that will be made public under a GPLv3 (GNU General Public License version 3) licence. This allows for reuse, distribution, adaptation, and requires for the adaptations to be distributed under the same licence.
I would enjoy to see further development in the future and would be willing to support it as best I can.
Also, an upgrade to Unreal Engine 5 would be nice, as the new version of the engine would make game development much easier. 
The use of __Lumen__, Unreal Engine's new lighting system, [Lumen](https://docs.unrealengine.com/5.0/en-US/lumen-global-illumination-and-reflections-in-unreal-engine/), added in UE 5, reduces development time substantially by not having to constantly rebuild lights, as is still necessary in previous versions. 

With respect to the designated platform the game was published on, while this implementation was only released for Android devices, it would be interesting to see whether an iPhone implementation could influence even more people to act positively towards global warming.
Additionally, the character controller and player pawn could be changed with each new level, adding a more open-worldly feel to the game and giving it even more of a distinguishing character.
The implementation of different personae, as suggested in the beginning of the chapter, in order to display a more multi-faceted view of the difficulties of implementing changes and how they actually affect the emission of CO2, would be a welcome addition, too.
A better way to incorporate social features is one of the main enjoyment aspects that the game is lacking.
Perhaps a leader board would suffice to remedy that.
Some kind of multiplayer feature would definitely make this title more appealing to a large group of players.
Finally, more optimisation work would have to be done to support all types of mobile devices.
Although the game was very playable on older devices, a Samsung A9 Tablet and an LG Nexus 5, the graphics of some levels needed a long time to fully load.
Releasing the game as a fully fledged title would give a broader audience the chance to play the title and be motivated to do their part in making our world a little more environmentally friendly.

## Authors and acknowledgment
Many thanks to my wife Johanna for proof reading, Swen Wessel who helped with the graphics, the students of Prof. Norbert Reintje's Industrial Ecology class, Christian Lohaus and Jennifer Albrecht for the initial brain storming session, Fabio Anthony and my mother in law for taking care of little Ada so often.
