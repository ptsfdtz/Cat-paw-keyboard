document.addEventListener('DOMContentLoaded', () => {
    const pawCenter = document.getElementById('pawCenter');
    const pawFirst = document.getElementById('pawFirst');
    const pawSecond = document.getElementById('pawSecond');
    const pawThird = document.getElementById('pawThird');
    const pawFourth = document.getElementById('pawFourth');

    pawCenter.addEventListener('click', () => console.log('Center paw clicked!'));
    pawFirst.addEventListener('click', () => console.log('First paw clicked!'));
    pawSecond.addEventListener('click', () => console.log('Second paw clicked!'));
    pawThird.addEventListener('click', () => console.log('Third paw clicked!'));
    pawFourth.addEventListener('click', () => console.log('Fourth paw clicked!'));
});