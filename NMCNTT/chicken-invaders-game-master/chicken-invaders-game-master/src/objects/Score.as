package objects
{
	import starling.display.Sprite;
	import starling.text.TextField;
	/**
	 *  Creating the scoreboard instance of the game.
	 * 
	 * 
	 * */
	public class Score extends Sprite
	{
		private var score:TextField;
		public function Score()
		{
			// Creating an instance of a textfield
			score = new TextField(300, 100, "0", "Verdana", 32, 0xFFFFFF);
			score.hAlign = "right";
			addChild(score);
		}
		
		public function addScore(amount:Number):void
		{
		score.text = (parseInt(score.text) + amount).toString();
		
		}
	}
}