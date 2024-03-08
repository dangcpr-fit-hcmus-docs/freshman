package views
{
	
	import flash.display.Sprite;
	
	import flashx.textLayout.formats.BackgroundColor;
	
	import starling.core.Starling;
	/**
	 * 
	 * 
	 * Creating the stage for the game 
	 * @author Peter Shodeinde
	 * 
	 */
	[SWF(width=1000, height=800, frameRate=60, BackgroundColor=0x000000)]
	public class ChickenInvader extends Sprite
	{
		public function ChickenInvader()
		{
			//Create a new object of the starling Game world
			var star:Starling = new Starling(Game, stage);
			star.showStats = true;
			//starting starling instance
			star.start();
		}
	}
}