package views
{
	 
	
	import flash.media.Sound;
	import flash.media.SoundTransform;
	
	import starling.textures.Texture;
	import starling.textures.TextureAtlas;
	/**
	 * This class will be used to loaded all the assets used in the game
	 * @author Peter Shodeinde
	 * 
	 * */
	public class Assets
	{
		//Embedded the background image
		
		[Embed(source="assets/background.png")]
		private static var background:Class;
		public static var backgroundTexture:Texture;
		// loading the atlas.png file that contains most of the assets in the game.
		[Embed(source="assets/atlas.png")]
		private static var atlas:Class;
		public static var ta:TextureAtlas;
		// loading the asset.xml file for the game assets information on the atlas.png and their coordinates
		[Embed(source="assets/atlas.xml", mimeType="application/octet-stream")]
		private static var atlasXML:Class;
		// Loading the explosion effects
		[Embed(source="assets/explosion.pex", mimeType="application/octet-stream")]
		public static var explosionXML:Class;
		// Loading the shooting file for the sound effect
		[Embed(source="assets/shoot.mp3")]
		private static var shootSound:Class;
		public static var shoot:Sound;
		// Loading the explosion file for the sound effect when the chicken are shoot
		[Embed(source="assets/explosion.mp3")]
		private static var explosionSound:Class;
		public static var explosion:Sound;
		
		
		// Initializing
		public static function init():void
		{
			backgroundTexture = Texture.fromBitmap(new background());
			
			// to get texture for our assets
			ta = new TextureAtlas(Texture.fromBitmap(new atlas()),
				XML(new atlasXML()));
			
			explosion = new explosionSound();
			explosion.play(0,0, new SoundTransform(0));
			
			shoot = new shootSound();
			shoot.play(0,0, new SoundTransform(0));
		}
	}
}