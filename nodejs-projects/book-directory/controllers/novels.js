const book = require('../models/book');
const bookModel = require('../models/book')

const getAllBooks = async (req, res) => {
  try{
      const books = await bookModel.find({});
      res.status(200).json({books});
  }catch(error){
      res.status(500).json({msg:error});

  }
}

const createBook = async (req,res) => {
  try {
    console.log(req.body)
    const book = await bookModel.create(req.body);
    res.status(201).json({book});
  } catch (error) {
    res.status(500).json({msg:error});
  }
}

const getBook = async (req, res) => {
  try{
    const authorToLookFor = req.params.author;
    //console.log("tried")
    const result = await bookModel.findOne({author:authorToLookFor})
    if(!result){
      return res.status(404).send(`No book with author ${author}`);
    }
    res.status(200).json({result})
  }catch(error){
    res.status(500).json({msg:error});   
  }
}

const modBook = async (req, res) => {
  try {
    //console.log('trying')
    const titleToLookFor = req.params.title;
    const result = await bookModel.findOneAndReplace({title:titleToLookFor}, req.body);
    if (!result){
      return res.status(404).send(`No book with title ${title}`);
    }
    res.status(200).json({result});
  }catch(error){
    //console.log('not trying')
    res.status(500).json({msg:error});
  }
}

const delBook = async (req, res) => {
  try {
    const titleDelete = req.params.title
    const result = await bookModel.findOneAndRemove({title:titleDelete});
    if(!result){
      return res.status(404).send(`No book with title ${title}`);
    }
    res.status(200).json({result});
  } catch(error) {
    res.status(500).json({msg:error});
  }
}

module.exports = {getAllBooks, createBook, getBook, modBook, delBook};