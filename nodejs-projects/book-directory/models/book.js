const mongoose = require('mongoose');

const bookSchema = new mongoose.Schema({
    id: {
        type: Number,
        required: [true, 'Must provide ID']
    },
    author: {
        type: String,
        maxLength: [50, 'Name can not have more than 50 characters']
    },
    title: {
        type: String,
        maxLength: [50, 'Title can not have more than 50 characters'],
        required: [true, 'Must provide title']
    },
    pages: {
        type: Number,
    }
})

module.exports = mongoose.model('bookModel', bookSchema)