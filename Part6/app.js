var five = require('johnny-five');
var twit = require('twit');

var client = new twit({
  consumer_key: 'PQKOJpCBhmmJwdNsTDYKAnzoz',
  consumer_secret: 'mmFKsbF0ShvkjHrnuQUkUMmDf2oKzGD0lW0EYlzfzjQON1NNeY',
  access_token: '1868251434-nyeTf6qQcB2dcxXLe68YkLzoyF21uZ5JfojRkEo',
  access_token_secret: 'OFN6fTCVLAjfqs3sKDaSCHTUx4c0mnrp3bPLtMrmJLQYk'
});

var board = new five.Board();
board.on("ready", function(){
  console.log("board ready");
  var pressed = false;
  var button = new five.Button(13);
  var led = new five.Led.RGB({
    pins: {
      red: 6,
      green: 5,
      blue: 3
    }
  });
  var piezo = new five.Piezo(9);
  this.repl.inject({
    led: led,
    button: button,
    piezo: piezo
  });
  led.off();


  button.on("down", function(){
    led.off();
    led.stop();
    console.log('Pressed');
  });


  var stream = client.stream('user');
  console.log("Starting stream thing");
  stream.on('direct_message', function(eventMsg){
    console.log("Message Received");
    led.on();
    led.color("#FF0000");

    led.blink(1000);
    piezo.play({
      song: "C D F D A",
      beats: 1 / 4,
      tempo: 100
    });
  });

  //If you are retweeted or tweeted at
  stream.on('tweet', function(event){
    console.log("Tweet event");
    led.on();
    led.color("#0000FF");

    led.blink(1000);
    piezo.play({
      song: "G G G G F F F F",
      beats: 1 / 4,
      tempo: 100
    });
  });

  //If your tweet gets favorited
  stream.on('favorite', function(event){
    console.log("Favorite event");
    led.on();
    led.color("#00FF00");

    led.blink(1000);
    piezo.play({
      song: "A A A A G G G G",
      beats: 1 / 4,
      tempo: 100
    });
  })


});
