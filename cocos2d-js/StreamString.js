/**********************************************************************
文字列を先頭から順に1文字ずつ表示する
**********************************************************************/
var StreamString = cc.Layer.extend({
	ctor:function(){
		this._super();
		return true;
	},
	init:function(message){
		var size = cc.winSize;
		
		this.msg = message;
		this.msgLabel = cc.LabelTTF.create("");
		// 左詰め
		this.msgLabel.setHorizontalAlignment(cc.TEXT_ALIGNMENT_LEFT);
		// 表示位置指定
		this.msgLabel.setPosition(size.width*0.5, size.height*0.5);
		// 表示範囲指定
		this.msgLabel.setDimensions(size.width, 0);
		
		this.cnt = 0;
		this.addChild(this.msgLabel);
		// 0.05秒おきにupdateが呼ばれる
		this.schedule(this.update, 0.05);
	},
	update:function(){
		if( this.cnt > this.msg.length ) {
			this.unschedule(this.update);
		}
//		cc.log(this.msgLabel.getString());
		// 先頭からthis.cnt分の文字列を設定
		this.msgLabel.setString(this.msg.substring(0, this.cnt));
		this.cnt++;
	}
	
});

StreamString.create = function() {
	var ss = new StreamString();
	return ss;
};