# note
> Work in progress.

`note` is a CLI notetaking tool that allows users to take notes in
Markdown. Just run `note new` and it'll automatically create a note
entry in your notes directory, then opens your text editor of choice
immediately after. All note entries have a predictable and descriptive
file-naming scheme that is directly based off of the [`denote` emacs
package](https://protesilaos.com/emacs/denote).

## TODO List
* [X] Create predictable, descriptive file names
* [X] Read configuration file found in `<user's config
      directory>/note/config.json`
* [ ] Create note files
* [ ] Automatically open text editor
* [ ] Implement note filtering commands
* [ ] Allow renaming any note entry based only on its front matter
* [ ] Implement `help` and `version` commands

## Usage

### Overview

    note help
    note version

    note new [title] [tags...]
    note ls [number | filter <title|tag|date> <query>]
    note rename <note_entry>
    note export
