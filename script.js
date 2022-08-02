var speech = window.webkitSpeechRecognition

var recognition= new speech()

var textbox= $("#text-box")

var instructions= $("#instructions")

var content= ''

recognition.continuous= true

recognition.onstart= function(){
    instructions.text("من فضلك إبدأ التحدث")
}



recognition.onresult= function(event){
    var current = event.resultIndex;
    var transcript= event.results[current][0].transcript
    content += transcript
    textbox.val(content)
}

$("#btn-start").click(function(event){
    if(content.length){
        content += ' '

    }
    recognition.start();

})
$("#btn-end").click(function(event){
    recognition.stop();
    instructions.text("اضغط وابدأ الحديث")
})
textbox.on('input',function(){
    content= $(this).val()
})